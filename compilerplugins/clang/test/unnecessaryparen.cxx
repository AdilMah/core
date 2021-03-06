/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 100 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

bool foo(int);

enum class EFoo { Bar };

int main()
{
    int x = 1;
    x = ((2)); // expected-error {{parentheses around parentheses [loplugin:unnecessaryparen]}}

    if ((foo(1))) foo(2); // expected-error {{parentheses immediately inside if statement [loplugin:unnecessaryparen]}}

    foo((1)); // expected-error {{parentheses immediately inside single-arg call [loplugin:unnecessaryparen]}}

    int y = (x); // expected-error {{unnecessary parentheses around identifier [loplugin:unnecessaryparen]}}
    (void)y;

    EFoo foo = EFoo::Bar;
    switch (foo) {
        case (EFoo::Bar): break; // expected-error {{parentheses immediately inside case statement [loplugin:unnecessaryparen]}}
    }

    // lots of our code uses this style, which I'm loathe to bulk-fix as yet
    int z = (y) ? 1 : 0;
    (void)z;

    int v1 = (static_cast<short>(1)) + 1; // expected-error {{unnecessary parentheses around cast [loplugin:unnecessaryparen]}}
    (void)v1;

    // No warnings, used to silence -Wunreachable-code:
    if ((false)) {
        return 0;
    }
    x = (true) ? 0 : 1;
};

/* vim:set shiftwidth=4 softtabstop=4 expandtab cinoptions=b1,g0,N-s cinkeys+=0=break: */
