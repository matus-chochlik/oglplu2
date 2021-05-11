/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "../../main_ctx.hpp"
#include <eagine/message_bus/blobs.hpp>
#define BOOST_TEST_MODULE EAGINE_msgbus_blobs
#include "../unit_test_begin.inl"

#include <map>

BOOST_AUTO_TEST_SUITE(msgbus_blobs_tests)

static eagine::test_random_generator rg;
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(msgbus_pending_blob_1) {
    using namespace eagine;

    for(int i = 0; i < test_repeats(100, 1000); ++i) {

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

    for(int i = 0; i < test_repeats(50, 200); ++i) {

        memory::buffer test_blob{};
        test_blob.resize(rg.get_span_size(16, 16 * 1024));
        rg.fill(cover(test_blob));

        msgbus::pending_blob pending{};
        pending.blob = memory::buffer{};
        pending.blob.resize(test_blob.size());
        pending.init();

        span_size_t pos = 0;
        while(!pending.is_complete() && (pos < test_blob.size())) {
            if(rg.get_int(0, 2) == 0) {
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

    std::map<message_id, memory::buffer> test_blobs{};

    while(test_blobs.size() < test_repeats(200, 1000)) {
        const auto key = message_id(rg.get_identifier(), rg.get_identifier());

        if(!(key == EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt))) {
            test_blobs[key] = memory::buffer{};
            auto& test_blob = test_blobs[key];
            test_blob.resize(rg.get_span_size(16, 1024));
            rg.fill(cover(test_blob));
        }
    }

    test_main_ctx tmc;
    msgbus::blob_manipulator blobs{tmc};

    for(const auto& [key, blob] : test_blobs) {
        blobs.push_outgoing(
          key,
          0,
          0,
          view(blob),
          {std::chrono::seconds(3600)},
          msgbus::message_priority::critical);
    }

    auto fake_send =
      [&blobs](message_id mid, const msgbus::message_view& msg) -> bool {
        BOOST_CHECK((mid == EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt)));

        auto allow = [](message_id) -> bool {
            return true;
        };
        return blobs.process_incoming(
          msgbus::blob_manipulator::filter_function(allow), msg);
    };

    blobs.process_outgoing({construct_from, fake_send}, 8 * 1024);

    auto test_fetch = [&test_blobs](
                        message_id mid,
                        msgbus::message_age,
                        const msgbus::message_view& msg) -> bool {
        BOOST_CHECK(msg.priority == msgbus::message_priority::critical);

        auto pos = test_blobs.find(mid);
        BOOST_CHECK(pos != test_blobs.end());
        if(pos != test_blobs.end()) {
            auto& test_blob = pos->second;
            BOOST_CHECK_EQUAL(msg.data.size(), test_blob.size());
            BOOST_CHECK(are_equal(msg.data, view(test_blob)));
        }
        return true;
    };

    const auto count = blobs.fetch_all({construct_from, test_fetch});

    BOOST_CHECK_EQUAL(count, test_blobs.size());
}
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(msgbus_blob_manipulator_2) {
    using namespace eagine;

    std::map<message_id, memory::buffer> test_blobs{};

    while(test_blobs.size() < test_repeats(200, 1000)) {
        const auto key =
          message_id(rg.get_identifier().value(), rg.get_identifier().value());

        if(!(key == EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt))) {
            test_blobs[key] = memory::buffer{};
            auto& test_blob = test_blobs[key];
            test_blob.resize(rg.get_span_size(16, 1024));
            rg.fill(cover(test_blob));
        }
    }

    test_main_ctx tmc;
    msgbus::blob_manipulator blobs{tmc};

    auto fake_send =
      [&blobs](message_id mid, const msgbus::message_view& msg) -> bool {
        BOOST_CHECK((mid == EAGINE_MSG_ID(eagiMsgBus, blobFrgmnt)));

        auto allow = [](message_id) -> bool {
            return true;
        };
        return blobs.process_incoming(
          msgbus::blob_manipulator::filter_function(allow), msg);
    };

    auto test_fetch = [&test_blobs](
                        message_id mid,
                        msgbus::message_age,
                        const msgbus::message_view& msg) -> bool {
        BOOST_CHECK(msg.priority == msgbus::message_priority::high);

        auto pos = test_blobs.find(mid);
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
          key,
          0,
          0,
          view(blob),
          {std::chrono::seconds(3600)},
          msgbus::message_priority::high);

        blobs.process_outgoing({construct_from, fake_send}, 8 * 1024);

        count += blobs.fetch_all({construct_from, test_fetch});
    }

    BOOST_CHECK_EQUAL(count, test_blobs.size());
}
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
