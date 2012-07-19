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
#pragma once

#include "XmlElementSerializingContext.h"

class CParameterBlackboard;
class CSelectionCriteriaDefinition;

class CXmlDomainSerializingContext : public CXmlElementSerializingContext
{
public:
    CXmlDomainSerializingContext(string& strError, bool bWithSettings);

    // Settings to be serialized or not
    bool withSettings() const;

    // Value interpretation as Real or Raw
    void setValueSpaceRaw(bool bIsRaw);
    bool valueSpaceIsRaw() const;

    // Output Raw Format for user get value interpretation
    void setOutputRawFormat(bool bIsHex);
    bool outputRawFormatIsHex();

    // Criteria defintion
    void setSelectionCriteriaDefinition(const CSelectionCriteriaDefinition* pSelectionCriteriaDefinition);
    const CSelectionCriteriaDefinition* getSelectionCriteriaDefinition() const;

    // Auto validation of configurations
    void setAutoValidationRequired(bool bAutoValidationRequired);
    bool autoValidationRequired() const;
private:
    // Indicate wheter or not to import settings
    bool _bWithSettings;
    // Value Space
    bool _bValueSpaceIsRaw;
    // Output Raw Format
    bool _bOutputRawFormatIsHex;
    // Criteria defintion
    const CSelectionCriteriaDefinition* _pSelectionCriteriaDefinition;
    // Auto validation of configurations
    bool _bAutoValidationRequired;
};
