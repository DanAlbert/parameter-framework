/* 
 * INTEL CONFIDENTIAL
 * Copyright © 2011 Intel 
 * Corporation All Rights Reserved.
 * 
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel’s prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 * 
 * CREATED: 2011-06-01
 * UPDATED: 2011-07-27
 */
#include "ParameterFrameworkConfiguration.h"

#define base CElement

CParameterFrameworkConfiguration::CParameterFrameworkConfiguration()
    : _bTuningAllowed(false), _uiServerPort(0)
{
}

string CParameterFrameworkConfiguration::getKind() const
{
    return "ParameterFrameworkConfiguration";
}

bool CParameterFrameworkConfiguration::childrenAreDynamic() const
{
    return true;
}

// System class name
const string& CParameterFrameworkConfiguration::getSystemClassName() const
{
    return _strSystemClassName;
}

// Tuning allowed
bool CParameterFrameworkConfiguration::isTuningAllowed() const
{
    return _bTuningAllowed;
}

// Server port
uint16_t CParameterFrameworkConfiguration::getServerPort() const
{
    return _uiServerPort;
}

// From IXmlSink
bool CParameterFrameworkConfiguration::fromXml(const CXmlElement& xmlElement, CXmlSerializingContext& serializingContext)
{
    // System class name
    _strSystemClassName = xmlElement.getAttributeString("SystemClassName");

    // Tuning allowed
    _bTuningAllowed = xmlElement.getAttributeBoolean("TuningAllowed");

    // Server port
    _uiServerPort = (uint16_t)xmlElement.getAttributeInteger("ServerPort");

    // Base
    return base::fromXml(xmlElement, serializingContext);
}
