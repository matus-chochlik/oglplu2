/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "../../main_ctx.hpp"
#include <eagine/message_bus/message.hpp>
#define BOOST_TEST_MODULE EAGINE_msgbus_serialized_storage
#include "../unit_test_begin.inl"

#include <map>
#include <vector>

BOOST_AUTO_TEST_SUITE(msgbus_serialized_storage_tests)

static eagine::test_random_generator rg;
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(msgbus_serialized_storage_1) {
    using namespace eagine;

    test_main_ctx tmc;
    main_ctx_object mco{EAGINE_ID(TestObj), tmc};
    std::array<byte, 4 * 1024> temp_buffer{};
    std::array<byte, 4 * 1024> pack_buffer{};
    memory::buffer test_data{};
    msgbus::connection_outgoing_messages com;
    msgbus::connection_incoming_messages cim;

    const std::array<message_id, 10> msgids{
      {EAGINE_MSG_ID(eagiTest1, message1),
       EAGINE_MSG_ID(eagiTest1, message2),
       EAGINE_MSG_ID(eagiTest1, message3),
       EAGINE_MSG_ID(eagiTest1, message4),
       EAGINE_MSG_ID(eagiTest1, message5),
       EAGINE_MSG_ID(eagiTest2, message6),
       EAGINE_MSG_ID(eagiTest2, message7),
       EAGINE_MSG_ID(eagiTest2, message8),
       EAGINE_MSG_ID(eagiTest2, message9),
       EAGINE_MSG_ID(eagiTest2, message0)}};

    std::map<msgbus::message_sequence_t, std::tuple<message_id, span_size_t>>
      msg_infos;

    msgbus::message_sequence_t total_sent = 0;
    msgbus::message_sequence_t total_rcvd = 0;

    auto test_handler = [&msg_infos, &total_rcvd](
                          auto msgid, auto, auto msg) -> bool {
        BOOST_ASSERT(!msg_infos.empty());
        auto& [cmpid, cmpsz] = msg_infos[msg.sequence_no];
        BOOST_CHECK(msgid == cmpid);
        BOOST_CHECK_EQUAL(msg.data.size(), cmpsz);
        msg_infos.erase(msg.sequence_no);
        ++total_rcvd;
        return true;
    };

    // for(int i = 0; i < test_repeats(100, 1000); ++i) {
    for(int i = 0; i < test_repeats(1, 1); ++i) {

        for(int s = 0, n = rg.get_int(20, 100); s < n; ++s) {
            const auto size = rg.get_span_size(1, 3 * 1024);
            test_data.resize(size);

            const message_id msgid = rg.pick_one_of(msgids);
            msgbus::message_view msg{memory::const_block{test_data}};
            msg.set_sequence_no(total_sent);

            const auto enqueued =
              com.enqueue(mco, msgid, msg, cover(temp_buffer));
            BOOST_ASSERT(enqueued);

            msg_infos[total_sent++] = {msgid, size};
        }

        BOOST_CHECK(!com.empty());

        for(int p = 0, n = rg.get_int(1, 100); p < n; ++p) {
            const auto packed = com.pack_into(cover(pack_buffer));
            if(!com.empty()) {
                BOOST_ASSERT(packed);
                cim.push(view(pack_buffer));
                com.cleanup(packed);
            }
        }

        while(!cim.empty()) {
            cim.fetch_messages(mco, {construct_from, test_handler});
        }
    }

    while(!com.empty()) {
        const auto packed = com.pack_into(cover(pack_buffer));
        BOOST_ASSERT(packed);
        cim.push(view(pack_buffer));
        com.cleanup(packed);
        cim.fetch_messages(mco, {construct_from, test_handler});
    }

    BOOST_CHECK_EQUAL(total_sent, total_rcvd);
    BOOST_CHECK(cim.empty());
    BOOST_CHECK_EQUAL(msg_infos.size(), 0);
}
//------------------------------------------------------------------------------
BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
