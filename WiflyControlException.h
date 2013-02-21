/**
 Copyright (C) 2012, 2013 Nils Weiss, Patrick Bruenn.
 
 This file is part of Wifly_Light.
 
 Wifly_Light is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 Wifly_Light is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Wifly_Light.  If not, see <http://www.gnu.org/licenses/>. */


#ifndef ____WiflyControlException__
#define ____WiflyControlException__

#include <stdio.h>
#include <exception>
#include <string>
#include "wifly_cmd.h"
#include "BlRequest.h"
#include "WiflyControlResponse.h"


class WiflyControlException : public std::exception
{
public:
	WiflyControlException(const std::string errorString = "WiflyControlException")
	: std::exception(), m_ErrorString(errorString) {};
		
	const std::string& GetErrorString(void) const { return m_ErrorString; };
	
private:
	const std::string m_ErrorString;
};

class BlNoResponseException: public WiflyControlException
{
public:
	BlNoResponseException(const struct BlRequest failedRequest, const std::string errorString)
	: WiflyControlException(errorString), m_FailedRequest(failedRequest) {};
	
	const struct BlRequest& GetFailedRequest(void) const { return m_FailedRequest; };
	
private:
	struct BlRequest m_FailedRequest;
};

class FwNoResponseException : public WiflyControlException
{
public:
	FwNoResponseException(const struct cmd_frame* const failedFrame, const WiflyResponse *pResponseObj, const std::string errorString)
	: WiflyControlException(errorString) { memcpy(&m_FailedFrame, failedFrame, sizeof(struct cmd_frame)); m_Response = pResponseObj; }
	
	const struct cmd_frame GetFailedFrame(void) const { return m_FailedFrame; };
	const WiflyResponse* GetResponseObj(void) const {return m_Response; };
	
private:
	struct cmd_frame m_FailedFrame;
	const WiflyResponse* m_Response;
};

class ScriptBufferFullException : public WiflyControlException
{
public:
	ScriptBufferFullException(const struct cmd_frame* const failedCommand, const std::string errorString)
	: WiflyControlException(errorString) { memcpy(&m_FailedCommand, failedCommand, sizeof(struct cmd_frame)); }
	
	const struct cmd_frame GetFailedCommand(void) const { return m_FailedCommand; }
	
private:
	struct cmd_frame m_FailedCommand;
};



#endif /* defined(____WiflyControlException__) */