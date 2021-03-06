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

#ifndef INCLUDED_EXTENSIONS_SOURCE_PROPCTRLR_DEFAULTHELPPROVIDER_HXX
#define INCLUDED_EXTENSIONS_SOURCE_PROPCTRLR_DEFAULTHELPPROVIDER_HXX

#include <com/sun/star/inspection/XPropertyControlObserver.hpp>
#include <com/sun/star/lang/XInitialization.hpp>
#include <com/sun/star/inspection/XObjectInspectorUI.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>

#include <cppuhelper/implbase.hxx>

namespace vcl { class Window; }


namespace pcr
{


    //= DefaultHelpProvider

    typedef ::cppu::WeakImplHelper <   css::inspection::XPropertyControlObserver
                                    ,   css::lang::XInitialization
                                    >   DefaultHelpProvider_Base;
    class DefaultHelpProvider final : public DefaultHelpProvider_Base
    {
    private:
        bool                            m_bConstructed;
        css::uno::Reference< css::inspection::XObjectInspectorUI >
                                        m_xInspectorUI;

    public:
        DefaultHelpProvider();

        // XServiceInfo - static versions
        /// @throws css::uno::RuntimeException
        static OUString getImplementationName_static(  );
        /// @throws css::uno::RuntimeException
        static css::uno::Sequence< OUString > getSupportedServiceNames_static(  );
        static css::uno::Reference< css::uno::XInterface > SAL_CALL
                        Create(const css::uno::Reference< css::uno::XComponentContext >&);

    private:
        virtual ~DefaultHelpProvider() override;

        // XPropertyControlObserver
        virtual void SAL_CALL focusGained( const css::uno::Reference< css::inspection::XPropertyControl >& Control ) override;
        virtual void SAL_CALL valueChanged( const css::uno::Reference< css::inspection::XPropertyControl >& Control ) override;

        // XInitialization
        virtual void SAL_CALL initialize( const css::uno::Sequence< css::uno::Any >& aArguments ) override;

        // Service constructors
        void    create( const css::uno::Reference< css::inspection::XObjectInspectorUI >& _rxUI );

        static vcl::Window* impl_getVclControlWindow_nothrow( const css::uno::Reference< css::inspection::XPropertyControl >& _rxControl );
        static OUString impl_getHelpText_nothrow( const css::uno::Reference< css::inspection::XPropertyControl >& _rxControl );
    };


} // namespace pcr


#endif // INCLUDED_EXTENSIONS_SOURCE_PROPCTRLR_DEFAULTHELPPROVIDER_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
