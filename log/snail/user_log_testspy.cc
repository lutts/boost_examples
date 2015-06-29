// Copyright (c) 2015
// All rights reserved.
//
// Author: Lutts Cao <<lutts.cao@gmail.com>>
//
// [Desc]

#include "log/snail/user_log_testspy.h"
#include "log/snail/log.h"

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/attributes/value_extraction.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;

BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", LogSeverityLevel)

UserLogTestSpy::UserLogTestSpy() {
  typedef sinks::synchronous_sink< sinks::text_ostream_backend > text_sink;
  boost::shared_ptr< text_sink > sink = boost::make_shared< text_sink >();

  sink->locked_backend()->add_stream(
      boost::make_shared< std::stringstream >());

  sink->set_filter(expr::attr<LogSeverityLevel>("Severity") == LogSeverityLevel::user); // NOLINT
  sink->set_formatter([this](logging::record_view const& rec,
                         logging::formatting_ostream&) {
                        actual_messages.push_back(rec[expr::smessage].get());
                      });

  logging::core::get()->add_sink(sink);

  enableDisableLog(true);
}

UserLogTestSpy::~UserLogTestSpy() {
  enableDisableLog(false);

  logging::core::get()->remove_all_sinks();
}
