/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LOG4CXX_FILTER_LOGGER_MATCH_FILTER_H
#define _LOG4CXX_FILTER_LOGGER_MATCH_FILTER_H

#include <log4cxx/spi/filter.h>
#include <log4cxx/level.h>

namespace log4cxx
{
class Level;

namespace filter
{
/**
   This is a very simple filter based on logger name matching.

   <p>The filter admits two options <code>loggerToMatch</code> and
   <code>acceptOnMatch</code>. If there is an exact match between the value
   of the <code>loggerToMatch</code> option and the logger of the
   {@link spi::LoggingEvent LoggingEvent}, then the #decide method returns
   {@link spi::Filter#ACCEPT ACCEPT} in case the <code>acceptOnMatch</code> option value is set
   to <code>true</code>, if it is <code>false</code> then
   {@link spi::Filter#DENY} is returned. If there is no match,
   {@link spi::Filter#NEUTRAL} is returned.
   A loggerToMatch of "root" matches both the root logger and a logger named "root".

   */

class LOG4CXX_EXPORT LoggerMatchFilter : public spi::Filter
{
	private:
		struct LoggerMatchFilterPrivate;

	public:
		typedef spi::Filter BASE_CLASS;
		DECLARE_LOG4CXX_OBJECT(LoggerMatchFilter)
		BEGIN_LOG4CXX_CAST_MAP()
		LOG4CXX_CAST_ENTRY(LoggerMatchFilter)
		LOG4CXX_CAST_ENTRY_CHAIN(BASE_CLASS)
		END_LOG4CXX_CAST_MAP()

		LoggerMatchFilter();
		~LoggerMatchFilter();

		/**
		\copybrief spi::OptionHandler::setOption()

		Supported options | Supported values | Default value
		-------------- | ---------------- | ---------------
		LoggerToMatch | {any} | root
		AcceptOnMatch | True,False | True
		*/
		void setOption(const LogString& option, const LogString& value) override;

		void setLoggerToMatch(const LogString& levelToMatch);

		LogString getLoggerToMatch() const;

		void setAcceptOnMatch(bool acceptOnMatch1);

		bool getAcceptOnMatch() const;

		/**
		Return the decision of this filter.

		Returns {@link spi::Filter#NEUTRAL NEUTRAL} if the
		<code>loggerToMatch</code> option is not set or if there is not match.
		Otherwise, if there is a match, then the returned decision is
		{@link spi::Filter#ACCEPT ACCEPT} if the <code>acceptOnMatch</code>
		property is set to <code>true</code>. The returned decision is
		{@link spi::Filter#DENY DENY} if the
		<code>acceptOnMatch</code> property is set to false.
		*/
		FilterDecision decide(const spi::LoggingEventPtr& event) const override;
}; // class LoggerMatchFilter
LOG4CXX_PTR_DEF(LoggerMatchFilter);
}  // namespace filter
} // namespace log4cxx

#endif // _LOG4CXX_FILTER_LOGGER_MATCH_FILTER_H
