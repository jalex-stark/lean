/*
Copyright (c) 2016 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Gabriel Ebner
*/
#pragma once
#if defined(SERVER)
#include "library/messages.h"
#include "util/json.hpp"

namespace lean {

using json = nlohmann::json;

json json_of_severity(message_severity sev);

json json_of_message(message const & msg);

class json_message_stream : public message_stream {
    std::ostream & m_out;
public:
    json_message_stream(std::ostream & out) : m_out(out) {}
    ~json_message_stream() {}
    void report(message const & msg) override;
};

}
#endif
