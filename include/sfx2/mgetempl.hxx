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
#ifndef INCLUDED_SFX2_MGETEMPL_HXX
#define INCLUDED_SFX2_MGETEMPL_HXX

#include <vcl/edit.hxx>
#include <vcl/fixed.hxx>
#include <vcl/lstbox.hxx>
#include <vcl/vclmedit.hxx>
#include <sfx2/styfitem.hxx>
#include <sfx2/tabdlg.hxx>
#include <memory>

/* expected:
    SID_TEMPLATE_NAME   :   In: StringItem, Name of Template
    SID_TEMPLATE_FAMILY :   In: Family of Template
*/

class SfxStyleFamilyItem;
class SfxStyleSheetBase;

class SfxManageStyleSheetPage final : public SfxTabPage
{
    SfxStyleSheetBase *pStyle;
    std::unique_ptr<SfxStyleFamilies> pFamilies;
    const SfxStyleFamilyItem *pItem;
    OUString aBuf;
    bool bModified;

    // initial data for the style
    OUString aName;
    OUString aFollow;
    OUString aParent;
    SfxStyleSearchBits const nFlags;

    std::unique_ptr<weld::Entry> m_xName;
    std::unique_ptr<weld::CheckButton> m_xAutoCB;
    std::unique_ptr<weld::Label> m_xFollowFt;
    std::unique_ptr<weld::ComboBox> m_xFollowLb;
    std::unique_ptr<weld::Button> m_xEditStyleBtn;
    std::unique_ptr<weld::Label> m_xBaseFt;
    std::unique_ptr<weld::ComboBox>          m_xBaseLb;
    std::unique_ptr<weld::Button> m_xEditLinkStyleBtn;
    std::unique_ptr<weld::Label> m_xFilterFt;
    std::unique_ptr<weld::ComboBox> m_xFilterLb;
    std::unique_ptr<weld::Label> m_xDescFt;
    std::unique_ptr<weld::Label> m_xNameFt;

friend class SfxStyleDialogController;

    DECL_LINK(GetFocusHdl, weld::Widget&, void);
    DECL_LINK(LoseFocusHdl, weld::Widget&, void);
    DECL_LINK(EditStyleSelectHdl_Impl, weld::ComboBox&, void);
    DECL_LINK(EditStyleHdl_Impl, weld::Button&, void);
    DECL_LINK(EditLinkStyleSelectHdl_Impl, weld::ComboBox&, void);
    DECL_LINK(EditLinkStyleHdl_Impl, weld::Button&, void);

    void    UpdateName_Impl(weld::ComboBox*, const OUString &rNew);
    void    SetDescriptionText_Impl();

    virtual ~SfxManageStyleSheetPage() override;
    virtual void dispose() override;

    static VclPtr<SfxTabPage> Create( TabPageParent pParent, const SfxItemSet* );

    virtual bool        FillItemSet(SfxItemSet *) override;
    virtual void        Reset(const SfxItemSet *) override;

    static bool    Execute_Impl( sal_uInt16 nId, const OUString& rStr, sal_uInt16 nFamily );
    using TabPage::ActivatePage;
    virtual void        ActivatePage(const SfxItemSet &) override;
    using TabPage::DeactivatePage;
    virtual DeactivateRC DeactivatePage(SfxItemSet *) override;

public:
    SfxManageStyleSheetPage(TabPageParent pParent, const SfxItemSet &rAttrSet);
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
