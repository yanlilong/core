/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SC_SOURCE_UI_INC_SHAREDOCDLG_HXX
#define INCLUDED_SC_SOURCE_UI_INC_SHAREDOCDLG_HXX

#include <vcl/button.hxx>
#include <vcl/dialog.hxx>
#include <vcl/fixed.hxx>
#include <scdllapi.h>

class ScViewData;
class ScDocShell;
class SvSimpleTable;

// class ScShareDocumentDlg

class ScShareDocumentDlg : public ModalDialog
{
private:
    VclPtr<CheckBox>           m_pCbShare;
    VclPtr<FixedText>          m_pFtWarning;
    VclPtr<SvSimpleTable>      m_pLbUsers;

    OUString            m_aStrNoUserData;
    OUString            m_aStrUnknownUser;
    OUString            m_aStrExclusiveAccess;

    ScDocShell*         mpDocShell;

    DECL_LINK( ToggleHandle, CheckBox&, void );

public:
           SC_DLLPUBLIC ScShareDocumentDlg( vcl::Window* pParent, ScViewData* pViewData );
                        virtual ~ScShareDocumentDlg() override;
    virtual void        dispose() override;

    bool                IsShareDocumentChecked() const;
    void                UpdateView();
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
