/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/message_bus/blobs.hpp>
#define BOOST_TEST_MODULE EAGINE_msgbus_blobs
#include "../unit_test_begin.inl"

#include <map>

BOOST_AUTO_TEST_SUITE(msgbus_blobs_tests)

static eagine::test_random_generator rg;
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(msgbus_pending_blob_1) {
    using namespace eagine;

    for(int i = 0; i < 1000; ++i) {

        memory::buffer test_blob{};
        test_blob.resize(rg.get_span_size(16, 16 * 1024));
        rg.fill(cover(test_blob));

        msgbus::pending_blob pending{};
        pending.blob = memory::buffer{};
        pending.blob.resize(test_blob.size());
        pending.init();

        span_size_t pos = 0;
        while(pos < pending.blob.size()) {
            auto fragment = head(
              skip(view(test_blob), pos),
              rg.get_span_size(0, test_blob.size() - pos));

            BOOST_CHECK(pending.merge_fragment(pos, fragment));
            pos += fragment.size();
        }

        BOOST_CHECK(pending.is_complete());
        BOOST_CHECK(are_equal(view(test_blob), view(pending.blob)));
    }
}
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(msgbus_pending_blob_2) {
    using namespace eagine;

    for(int i = 0; i < 100; ++i) {

        memory::buffer test_blob{};
        test_blob.resize(rg.get_span_size(16, 16 * 1024));
        rg.fill(cover(test_blob));

        msgbus::pending_blob pending{};
        pending.blob = memory::buffer{};
        pending.blob.resize(test_blob.size());
        pending.init();

        span_size_t pos = 0;
        while(!pending.is_complete() && (pos < test_blob.size())) {
            if(rg.get_bool()) {
                auto fragment = head(skip(view(test_blob), pos), 33);
                BOOST_CHECK(pending.merge_fragment(pos, fragment));
                pos += 17;
            } else {
                const auto rnd = rg.get_span_size(0, test_blob.size());
                auto fragment = head(
                  skip(view(test_blob), rnd),
                  rg.get_span_size(0, test_blob.size() - rnd));

                BOOST_CHECK(pending.merge_fragment(rnd, fragment));
            }
        }

        BOOST_CHECK(pending.is_complete());
        BOOST_CHECK(are_equal(view(test_blob), view(pending.blob)));
    }
}
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(msgbus_blob_manipulator_1) {
    using namespace eagine;

    std::map<message_id_tuple, memory::buffer> test_blobs{};

    while(test_blobs.size() < 1000) {
        const auto key = message_id_tuple(
          rg.get_identifier().value(), rg.get_identifier().value());

        if(!EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt).matches(key)) {
            test_blobs[key] = memory::buffer{};
            auto& test_blob = test_blobs[key];
            test_blob.resize(rg.get_span_size(16, 1024));
            rg.fill(cover(test_blob));
        }
    }

    msgbus::blob_manipulator blobs{};

    for(const auto& [key, blob] : test_blobs) {
        blobs.push_outgoing(
          key.class_id(),
          key.method_id(),
          0,
          view(blob),
          {std::chrono::seconds(3600)},
          msgbus::message_priority::critical);
    }

    auto fake_send = [&blobs](
                       identifier_t cid,
                       identifier_t mid,
                       const msgbus::message_view& msg) -> bool {
        BOOST_CHECK((EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt).matches(cid, mid)));

        auto allow = [](identifier_t, identifier_t) -> bool { return true; };
        return blobs.process_incoming(
          msgbus::blob_manipulator::filter_function(allow), msg);
    };

    blobs.process_outgoing(
      msgbus::blob_manipulator::send_handler(fake_send), 8 * 1024);

    auto test_fetch = [&test_blobs](
                        identifier_t cid,
                        identifier_t mid,
                        const msgbus::message_view& msg) -> bool {
        BOOST_CHECK(msg.priority == msgbus::message_priority::critical);

        auto pos = test_blobs.find(message_id_tuple(cid, mid));
        BOOST_CHECK(pos != test_blobs.end());
        if(pos != test_blobs.end()) {
            auto& test_blob = pos->second;
            BOOST_CHECK_EQUAL(msg.data.size(), test_blob.size());
            BOOST_CHECK(are_equal(msg.data, view(test_blob)));
        }
        return true;
    };

    const auto count =
      blobs.fetch_all(msgbus::blob_manipulator::fetch_handler(test_fetch));

    BOOST_CHECK_EQUAL(count, test_blobs.size());
}
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(msgbus_blob_manipulator_2) {
    using namespace eagine;

    std::map<message_id_tuple, memory::buffer> test_blobs{};

    while(test_blobs.size() < 1000) {
        const auto key = message_id_tuple(
          rg.get_identifier().value(), rg.get_identifier().value());

        if(!EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt).matches(key)) {
            test_blobs[key] = memory::buffer{};
            auto& test_blob = test_blobs[key];
            test_blob.resize(rg.get_span_size(16, 1024));
            rg.fill(cover(test_blob));
        }
    }

    msgbus::blob_manipulator blobs{};

    auto fake_send = [&blobs](
                       identifier_t cid,
                       identifier_t mid,
                       const msgbus::message_view& msg) -> bool {
        BOOST_CHECK((EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt).matches(cid, mid)));

        auto allow = [](identifier_t, identifier_t) -> bool { return true; };
        return blobs.process_incoming(
          msgbus::blob_manipulator::filter_function(allow), msg);
    };

    auto test_fetch = [&test_blobs](
                        identifier_t cid,
                        identifier_t mid,
                        const msgbus::message_view& msg) -> bool {
        BOOST_CHECK(msg.priority == msgbus::message_priority::high);

        auto pos = test_blobs.find(message_id_tuple(cid, mid));
        BOOST_CHECK(pos != test_blobs.end());
        if(pos != test_blobs.end()) {
            const auto& test_blob = pos->second;
            BOOST_CHECK_EQUAL(msg.data.size(), test_blob.size());
            BOOST_CHECK(are_equal(msg.data, view(test_blob)));
        }
        return true;
    };

    span_size_t count = 0;

    for(const auto& [key, blob] : test_blobs) {
        blobs.push_outgoing(
          key.class_id(),
          key.method_id(),
          0,
          view(blob),
          {std::chrono::seconds(3600)},
          msgbus::message_priority::high);

        blobs.process_outgoing(
          msgbus::blob_manipulator::send_handler(fake_send), 8 * 1024);

        count +=
          blobs.fetch_all(msgbus::blob_manipulator::fetch_handler(test_fetch));
    }

    BOOST_CHECK_EQUAL(count, test_blobs.size());
}
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
