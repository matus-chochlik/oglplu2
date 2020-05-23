/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/message_bus/blobs.hpp>
#define BOOST_TEST_MODULE EAGINE_msgbus_blobs
#include "../unit_test_begin.inl"

#include <eagine/random_bytes.hpp>
#include <map>

BOOST_AUTO_TEST_SUITE(msgbus_blobs_tests)

static eagine::test_random_generator rg;
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(msgbus_blobs_1) {
    using namespace eagine;

    std::map<message_id_tuple, memory::buffer> test_blobs{};

    while(test_blobs.size() < 100) {
        const auto key = message_id_tuple(
          rg.get_identifier().value(), rg.get_identifier().value());

        if(!EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt).matches(key)) {
            test_blobs[key] = memory::buffer{};
            auto& test_blob = test_blobs[key];
            test_blob.resize(rg.get_span_size(16, 1024));
            fill_with_random_bytes(cover(test_blob));
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
BOOST_AUTO_TEST_CASE(msgbus_blobs_2) {
    using namespace eagine;

    std::map<message_id_tuple, memory::buffer> test_blobs{};

    while(test_blobs.size() < 100) {
        const auto key = message_id_tuple(
          rg.get_identifier().value(), rg.get_identifier().value());

        if(!EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt).matches(key)) {
            test_blobs[key] = memory::buffer{};
            auto& test_blob = test_blobs[key];
            test_blob.resize(rg.get_span_size(16, 1024));
            fill_with_random_bytes(cover(test_blob));
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
