/*
Copyright (c) 2013 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Soonho Kong
*/
#include "util/test.h"
#include "util/trace.h"
#include "util/numerics/float.h"
#include "util/interval/interval_def.h"
#include "tests/interval/check.h"

using namespace lean;

using std::cout;
using std::endl;

typedef interval<float> flti;

static void float_interval_arith() {
    flti i1(1.0, 2.0);
    flti i2(3.0, 4.0);
    flti i3(-10.0, -5.0);
    flti i4(-3.0, +4.0);
    flti i5(5.0, 8.0);

    float c1 = 0.6;
    float c2 = 3.0;
    float c3 = 0.0;
    float c4 = -4.5;
    float c5 = -0.3;

    cout << "=====================" << endl;
    print_result(i1, "+", c1, i1 + c1);
    print_result(i2, "+", c2, i2 + c2);
    print_result(i3, "+", c3, i3 + c3);
    print_result(i4, "+", c4, i4 + c4);
    print_result(i5, "+", c5, i5 + c5);
    print_result(i5, "+", c1, i5 + c1);
    print_result(i4, "+", c2, i4 + c2);
    print_result(i2, "+", c4, i2 + c4);
    print_result(i1, "+", c5, i1 + c5);

    cout << "=====================" << endl;
    print_result(c1, "+", i1, c1 + i1);
    print_result(c2, "+", i2, c2 + i2);
    print_result(c3, "+", i3, c3 + i3);
    print_result(c4, "+", i4, c4 + i4);
    print_result(c5, "+", i5, c5 + i5);
    print_result(c5, "+", i1, c5 + i1);
    print_result(c4, "+", i2, c4 + i2);
    print_result(c2, "+", i4, c2 + i4);
    print_result(c1, "+", i5, c1 + i5);

    cout << "=====================" << endl;
    print_result(i1, "-", c1, i1 - c1);
    print_result(i2, "-", c2, i2 - c2);
    print_result(i3, "-", c3, i3 - c3);
    print_result(i4, "-", c4, i4 - c4);
    print_result(i5, "-", c5, i5 - c5);
    print_result(i5, "-", c1, i5 - c1);
    print_result(i4, "-", c2, i4 - c2);
    print_result(i2, "-", c4, i2 - c4);
    print_result(i1, "-", c5, i1 - c5);

    cout << "=====================" << endl;
    print_result(c1, "-", i1, c1 - i1);
    print_result(c2, "-", i2, c2 - i2);
    print_result(c3, "-", i3, c3 - i3);
    print_result(c4, "-", i4, c4 - i4);
    print_result(c5, "-", i5, c5 - i5);
    print_result(c5, "-", i1, c5 - i1);
    print_result(c4, "-", i2, c4 - i2);
    print_result(c2, "-", i4, c2 - i4);
    print_result(c1, "-", i5, c1 - i5);

    cout << "=====================" << endl;
    print_result(i1, "*", c1, i1 * c1);
    print_result(i2, "*", c2, i2 * c2);
    print_result(i3, "*", c3, i3 * c3);
    print_result(i4, "*", c4, i4 * c4);
    print_result(i5, "*", c5, i5 * c5);
    print_result(i5, "*", c1, i5 * c1);
    print_result(i4, "*", c2, i4 * c2);
    print_result(i2, "*", c4, i2 * c4);
    print_result(i1, "*", c5, i1 * c5);

    cout << "=====================" << endl;
    print_result(c1, "*", i1, c1 * i1);
    print_result(c2, "*", i2, c2 * i2);
    print_result(c3, "*", i3, c3 * i3);
    print_result(c4, "*", i4, c4 * i4);
    print_result(c5, "*", i5, c5 * i5);
    print_result(c5, "*", i1, c5 * i1);
    print_result(c4, "*", i2, c4 * i2);
    print_result(c2, "*", i4, c2 * i4);
    print_result(c1, "*", i5, c1 * i5);

    cout << "=====================" << endl;
    print_result(i1, "/", c1, i1 / c1);
    print_result(i2, "/", c2, i2 / c2);
    print_result(i3, "/", c3, i3 / c3);
    print_result(i4, "/", c4, i4 / c4);
    print_result(i5, "/", c5, i5 / c5);
    print_result(i5, "/", c1, i5 / c1);
    print_result(i4, "/", c2, i4 / c2);
    print_result(i2, "/", c4, i2 / c4);
    print_result(i1, "/", c5, i1 / c5);

    cout << "=====================" << endl;
    print_result(c1, "/", i1, c1 / i1);
    print_result(c2, "/", i2, c2 / i2);
    print_result(c3, "/", i3, c3 / i3);
    print_result(c5, "/", i5, c5 / i5);
    print_result(c5, "/", i1, c5 / i1);
    print_result(c4, "/", i2, c4 / i2);
    print_result(c1, "/", i5, c1 / i5);
}

static void float_interval_inf1() {
    flti i1(1.0, 2.0);
    flti inf;
    flti ozero_pinf;
    flti ozero_ninf;
    ozero_pinf.set_is_lower_inf(false);
    ozero_ninf.set_is_upper_inf(false);
    flti czero_pinf;
    flti czero_ninf;
    czero_pinf.set_is_lower_inf(false);
    czero_pinf.set_is_lower_open(false);
    czero_ninf.set_is_upper_inf(false);
    czero_ninf.set_is_upper_open(false);

    cout << i1 << " * " << ozero_ninf << " = " << i1 * ozero_ninf << endl;
    cout << i1 << " * " << ozero_pinf << " = " << i1 * ozero_pinf << endl;
    cout << i1 << " * " << czero_ninf << " = " << i1 * czero_ninf << endl;
    cout << i1 << " * " << czero_pinf << " = " << i1 * czero_pinf << endl;
    lean_assert(i1 * ozero_ninf == ozero_ninf); lean_assert(ozero_ninf * i1 == ozero_ninf);
    lean_assert(i1 * ozero_pinf == ozero_pinf); lean_assert(ozero_pinf * i1 == ozero_pinf);
    lean_assert(i1 * czero_ninf == czero_ninf); lean_assert(czero_ninf * i1 == czero_ninf);
    lean_assert(i1 * czero_pinf == czero_pinf); lean_assert(czero_pinf * i1 == czero_pinf);

    cout << "=== Addition between [0, +oo), (-oo, 0], (0, +oo), (-oo, 0) ===" << endl;
    cout << ozero_ninf << " + " << ozero_ninf << " = " << ozero_ninf + ozero_ninf << endl;
    cout << ozero_ninf << " + " << ozero_pinf << " = " << ozero_ninf + ozero_pinf << endl;
    cout << ozero_ninf << " + " << czero_ninf << " = " << ozero_ninf + czero_ninf << endl;
    cout << ozero_ninf << " + " << czero_pinf << " = " << ozero_ninf + czero_pinf << endl;
    cout << ozero_pinf << " + " << ozero_ninf << " = " << ozero_pinf + ozero_ninf << endl;
    cout << ozero_pinf << " + " << ozero_pinf << " = " << ozero_pinf + ozero_pinf << endl;
    cout << ozero_pinf << " + " << czero_ninf << " = " << ozero_pinf + czero_ninf << endl;
    cout << ozero_pinf << " + " << czero_pinf << " = " << ozero_pinf + czero_pinf << endl;
    cout << czero_ninf << " + " << ozero_ninf << " = " << czero_ninf + ozero_ninf << endl;
    cout << czero_ninf << " + " << ozero_pinf << " = " << czero_ninf + ozero_pinf << endl;
    cout << czero_ninf << " + " << czero_ninf << " = " << czero_ninf + czero_ninf << endl;
    cout << czero_ninf << " + " << czero_pinf << " = " << czero_ninf + czero_pinf << endl;
    cout << czero_pinf << " + " << ozero_ninf << " = " << czero_pinf + ozero_ninf << endl;
    cout << czero_pinf << " + " << ozero_pinf << " = " << czero_pinf + ozero_pinf << endl;
    cout << czero_pinf << " + " << czero_ninf << " = " << czero_pinf + czero_ninf << endl;
    cout << czero_pinf << " + " << czero_pinf << " = " << czero_pinf + czero_pinf << endl;

    lean_assert(ozero_ninf + ozero_ninf == ozero_ninf);
    lean_assert(ozero_ninf + ozero_pinf == inf);
    lean_assert(ozero_ninf + czero_ninf == ozero_ninf);
    lean_assert(ozero_ninf + czero_pinf == inf);
    lean_assert(ozero_pinf + ozero_ninf == inf);
    lean_assert(ozero_pinf + ozero_pinf == ozero_pinf);
    lean_assert(ozero_pinf + czero_ninf == inf);
    lean_assert(ozero_pinf + czero_pinf == ozero_pinf);
    lean_assert(czero_ninf + ozero_ninf == ozero_ninf);
    lean_assert(czero_ninf + ozero_pinf == inf);
    lean_assert(czero_ninf + czero_ninf == czero_ninf);
    lean_assert(czero_ninf + czero_pinf == inf);
    lean_assert(czero_pinf + ozero_ninf == inf);
    lean_assert(czero_pinf + ozero_pinf == ozero_pinf);
    lean_assert(czero_pinf + czero_ninf == inf);
    lean_assert(czero_pinf + czero_pinf == czero_pinf);

    cout << "=== Subtraction between [0, +oo), (-oo, 0], (0, +oo), (-oo, 0) ===" << endl;
    cout << ozero_ninf << " - " << ozero_ninf << " = " << ozero_ninf - ozero_ninf << endl;
    cout << ozero_ninf << " - " << ozero_pinf << " = " << ozero_ninf - ozero_pinf << endl;
    cout << ozero_ninf << " - " << czero_ninf << " = " << ozero_ninf - czero_ninf << endl;
    cout << ozero_ninf << " - " << czero_pinf << " = " << ozero_ninf - czero_pinf << endl;
    cout << ozero_pinf << " - " << ozero_ninf << " = " << ozero_pinf - ozero_ninf << endl;
    cout << ozero_pinf << " - " << ozero_pinf << " = " << ozero_pinf - ozero_pinf << endl;
    cout << ozero_pinf << " - " << czero_ninf << " = " << ozero_pinf - czero_ninf << endl;
    cout << ozero_pinf << " - " << czero_pinf << " = " << ozero_pinf - czero_pinf << endl;
    cout << czero_ninf << " - " << ozero_ninf << " = " << czero_ninf - ozero_ninf << endl;
    cout << czero_ninf << " - " << ozero_pinf << " = " << czero_ninf - ozero_pinf << endl;
    cout << czero_ninf << " - " << czero_ninf << " = " << czero_ninf - czero_ninf << endl;
    cout << czero_ninf << " - " << czero_pinf << " = " << czero_ninf - czero_pinf << endl;
    cout << czero_pinf << " - " << ozero_ninf << " = " << czero_pinf - ozero_ninf << endl;
    cout << czero_pinf << " - " << ozero_pinf << " = " << czero_pinf - ozero_pinf << endl;
    cout << czero_pinf << " - " << czero_ninf << " = " << czero_pinf - czero_ninf << endl;
    cout << czero_pinf << " - " << czero_pinf << " = " << czero_pinf - czero_pinf << endl;

    lean_assert(ozero_ninf - ozero_ninf == inf);
    lean_assert(ozero_ninf - ozero_pinf == ozero_ninf);
    lean_assert(ozero_ninf - czero_ninf == inf);
    lean_assert(ozero_ninf - czero_pinf == ozero_ninf);
    lean_assert(ozero_pinf - ozero_ninf == ozero_pinf);
    lean_assert(ozero_pinf - ozero_pinf == inf);
    lean_assert(ozero_pinf - czero_ninf == ozero_pinf);
    lean_assert(ozero_pinf - czero_pinf == inf);
    lean_assert(czero_ninf - ozero_ninf == inf);
    lean_assert(czero_ninf - ozero_pinf == ozero_ninf);
    lean_assert(czero_ninf - czero_ninf == inf);
    lean_assert(czero_ninf - czero_pinf == czero_ninf);
    lean_assert(czero_pinf - ozero_ninf == ozero_pinf);
    lean_assert(czero_pinf - ozero_pinf == inf);
    lean_assert(czero_pinf - czero_ninf == czero_pinf);
    lean_assert(czero_pinf - czero_pinf == inf);

    cout << "=== Multiplication between [0, +oo), (-oo, 0], (0, +oo), (-oo, 0) ===" << endl;
    cout << ozero_ninf << " * " << ozero_ninf << " = " << ozero_ninf * ozero_ninf << endl;
    cout << ozero_ninf << " * " << ozero_pinf << " = " << ozero_ninf * ozero_pinf << endl;
    cout << ozero_ninf << " * " << czero_ninf << " = " << ozero_ninf * czero_ninf << endl;
    cout << ozero_ninf << " * " << czero_pinf << " = " << ozero_ninf * czero_pinf << endl;
    cout << ozero_pinf << " * " << ozero_ninf << " = " << ozero_pinf * ozero_ninf << endl;
    cout << ozero_pinf << " * " << ozero_pinf << " = " << ozero_pinf * ozero_pinf << endl;
    cout << ozero_pinf << " * " << czero_ninf << " = " << ozero_pinf * czero_ninf << endl;
    cout << ozero_pinf << " * " << czero_pinf << " = " << ozero_pinf * czero_pinf << endl;
    cout << czero_ninf << " * " << ozero_ninf << " = " << czero_ninf * ozero_ninf << endl;
    cout << czero_ninf << " * " << ozero_pinf << " = " << czero_ninf * ozero_pinf << endl;
    cout << czero_ninf << " * " << czero_ninf << " = " << czero_ninf * czero_ninf << endl;
    cout << czero_ninf << " * " << czero_pinf << " = " << czero_ninf * czero_pinf << endl;
    cout << czero_pinf << " * " << ozero_ninf << " = " << czero_pinf * ozero_ninf << endl;
    cout << czero_pinf << " * " << ozero_pinf << " = " << czero_pinf * ozero_pinf << endl;
    cout << czero_pinf << " * " << czero_ninf << " = " << czero_pinf * czero_ninf << endl;
    cout << czero_pinf << " * " << czero_pinf << " = " << czero_pinf * czero_pinf << endl;

    lean_assert(ozero_ninf * ozero_ninf == ozero_pinf);
    lean_assert(ozero_ninf * ozero_pinf == ozero_ninf);
    lean_assert(ozero_ninf * czero_ninf == czero_pinf);
    lean_assert(ozero_ninf * czero_pinf == czero_ninf);
    lean_assert(ozero_pinf * ozero_ninf == ozero_ninf);
    lean_assert(ozero_pinf * ozero_pinf == ozero_pinf);
    lean_assert(ozero_pinf * czero_ninf == czero_ninf);
    lean_assert(ozero_pinf * czero_pinf == czero_pinf);
    lean_assert(czero_ninf * ozero_ninf == czero_pinf);
    lean_assert(czero_ninf * ozero_pinf == czero_ninf);
    lean_assert(czero_ninf * czero_ninf == czero_pinf);
    lean_assert(czero_ninf * czero_pinf == czero_ninf);
    lean_assert(czero_pinf * ozero_ninf == czero_ninf);
    lean_assert(czero_pinf * ozero_pinf == czero_pinf);
    lean_assert(czero_pinf * czero_ninf == czero_ninf);
    lean_assert(czero_pinf * czero_pinf == czero_pinf);

    cout << "=== Division between [0, +oo), (-oo, 0], (0, +oo), (-oo, 0) ===" << endl;
    cout << ozero_ninf << " / " << ozero_ninf << " = " << ozero_ninf / ozero_ninf << endl;
    cout << ozero_ninf << " / " << ozero_pinf << " = " << ozero_ninf / ozero_pinf << endl;
    cout << ozero_pinf << " / " << ozero_ninf << " = " << ozero_pinf / ozero_ninf << endl;
    cout << ozero_pinf << " / " << ozero_pinf << " = " << ozero_pinf / ozero_pinf << endl;
    cout << czero_ninf << " / " << ozero_ninf << " = " << czero_ninf / ozero_ninf << endl;
    cout << czero_ninf << " / " << ozero_pinf << " = " << czero_ninf / ozero_pinf << endl;
    cout << czero_pinf << " / " << ozero_ninf << " = " << czero_pinf / ozero_ninf << endl;
    cout << czero_pinf << " / " << ozero_pinf << " = " << czero_pinf / ozero_pinf << endl;

    lean_assert(ozero_ninf / ozero_ninf == ozero_pinf);
    lean_assert(ozero_ninf / ozero_pinf == ozero_ninf);
    lean_assert(ozero_pinf / ozero_ninf == ozero_ninf);
    lean_assert(ozero_pinf / ozero_pinf == ozero_pinf);
    lean_assert(czero_ninf / ozero_ninf == czero_pinf);
    lean_assert(czero_ninf / ozero_pinf == czero_ninf);
    lean_assert(czero_pinf / ozero_ninf == czero_ninf);
    lean_assert(czero_pinf / ozero_pinf == czero_pinf);
}

static void float_interval_inf2() {
    flti i1(1.0, 2.0);
    flti i2(3.0, 4.0);
    flti i3(-10.0, -5.0);
    flti i4(-3.0, +4.0);
    flti i5(5.0, 8.0);
    flti inf;

    float c1 = 0.6;
    float c2 = 3.0;
    float c3 = -0.3;
    float c4 = -4.5;
    float zero = 0.0;

    lean_assert(i1 + inf == inf);   lean_assert(inf + i1 == inf);
    lean_assert(i2 + inf == inf);   lean_assert(inf + i2 == inf);
    lean_assert(i3 + inf == inf);   lean_assert(inf + i3 == inf);
    lean_assert(i4 + inf == inf);   lean_assert(inf + i4 == inf);
    lean_assert(i5 + inf == inf);   lean_assert(inf + i5 == inf);
    lean_assert(c1 + inf == inf);   lean_assert(inf + c1 == inf);
    lean_assert(c2 + inf == inf);   lean_assert(inf + c2 == inf);
    lean_assert(c3 + inf == inf);   lean_assert(inf + c3 == inf);
    lean_assert(c4 + inf == inf);   lean_assert(inf + c4 == inf);
    lean_assert(zero + inf == inf); lean_assert(inf + zero == inf);

    lean_assert(i1 - inf == inf);   lean_assert(inf - i1 == inf);
    lean_assert(i2 - inf == inf);   lean_assert(inf - i2 == inf);
    lean_assert(i3 - inf == inf);   lean_assert(inf - i3 == inf);
    lean_assert(i4 - inf == inf);   lean_assert(inf - i4 == inf);
    lean_assert(i5 - inf == inf);   lean_assert(inf - i5 == inf);
    lean_assert(c1 - inf == inf);   lean_assert(inf - c1 == inf);
    lean_assert(c2 - inf == inf);   lean_assert(inf - c2 == inf);
    lean_assert(c3 - inf == inf);   lean_assert(inf - c3 == inf);
    lean_assert(c4 - inf == inf);   lean_assert(inf - c4 == inf);
    lean_assert(zero - inf == inf); lean_assert(inf - zero == inf);

    lean_assert(i1 * inf == inf);    lean_assert(inf * i1 == inf);
    lean_assert(i2 * inf == inf);    lean_assert(inf * i2 == inf);
    lean_assert(i3 * inf == inf);    lean_assert(inf * i3 == inf);
    lean_assert(i4 * inf == inf);    lean_assert(inf * i4 == inf);
    lean_assert(i5 * inf == inf);    lean_assert(inf * i5 == inf);
    lean_assert(c1 * inf == inf);    lean_assert(inf * c1 == inf);
    lean_assert(c2 * inf == inf);    lean_assert(inf * c2 == inf);
    lean_assert(c3 * inf == inf);    lean_assert(inf * c3 == inf);
    lean_assert(c4 * inf == inf);    lean_assert(inf * c4 == inf);
    lean_assert(zero * inf == zero); lean_assert(inf * zero == zero);
}

static void float_interval_trans() {
    flti i1(1.0, 2.0);
    flti i2(3.0, 4.0);
    flti i3(-10.0, -5.0);
    flti i4(-3.0, +4.0);
    flti i5(5.0, 8.0);
    flti i6(0.3, 1.67);
    flti i7(1.8, 3.5);
    flti i8(3.5, 4.9);
    flti i9(-3.15, -2.0);
    flti i10(-0.99, 0.5);
    flti i11(-0.8, -0.5);
    flti i12(-0.3, 0.2);
    flti i13(0.5, 0.9);
    flti i14(-0.1, 0.8);
    flti i15(-0.4, -0.3);

    flti oi1(1.0, 2.0);
    flti oi2(3.0, 4.0);
    flti oi3(-10.0, -5.0);
    flti oi4(-3.0, +4.0);
    flti oi5(5.0, 8.0);
    flti oi6(0.3, 1.67);
    flti oi7(1.8, 3.5);
    flti oi8(3.5, 4.9);
    flti oi9(-3.15, -2.0);
    flti oi10(-3.19, -1.0);
    flti oi11(-0.8, -0.5);
    flti oi12(-0.3, 0.2);
    flti oi13(0.5, 0.9);
    flti oi14(-0.1, 0.8);
    flti oi15(-0.4, -0.3);

    oi1.set_is_lower_open(true);  oi1.set_is_upper_open(true);
    oi2.set_is_lower_open(true);  oi2.set_is_upper_open(true);
    oi3.set_is_lower_open(true);  oi3.set_is_upper_open(true);
    oi4.set_is_lower_open(true);  oi4.set_is_upper_open(true);
    oi5.set_is_lower_open(true);  oi5.set_is_upper_open(true);
    oi6.set_is_lower_open(true);  oi6.set_is_upper_open(true);
    oi7.set_is_lower_open(true);  oi7.set_is_upper_open(true);
    oi8.set_is_lower_open(true);  oi8.set_is_upper_open(true);
    oi9.set_is_lower_open(true);  oi9.set_is_upper_open(true);
    oi10.set_is_lower_open(true); oi10.set_is_upper_open(true);
    oi11.set_is_lower_open(true); oi11.set_is_upper_open(true);
    oi12.set_is_lower_open(true); oi12.set_is_upper_open(true);
    oi13.set_is_lower_open(true); oi13.set_is_upper_open(true);
    oi14.set_is_lower_open(true); oi14.set_is_upper_open(true);
    oi15.set_is_lower_open(true); oi15.set_is_upper_open(true);

    flti inf;
    flti ozero_pinf;
    flti ozero_ninf;
    ozero_pinf.set_is_lower_inf(false);
    ozero_ninf.set_is_upper_inf(false);
    flti czero_pinf;
    flti czero_ninf;
    czero_pinf.set_is_lower_inf(false);
    czero_pinf.set_is_lower_open(false);
    czero_ninf.set_is_upper_inf(false);
    czero_ninf.set_is_upper_open(false);

    // float c1 = 0.6;
    // float c2 = 3.0;
    // float c3 = 0.0;
    // float c4 = -4.5;
    // float c5 = -0.3;

    cout << "=====================" << endl;
    check_bop(float, power, i1, 3u);
    check_bop(float, power, i2, 3u);
    check_bop(float, power, i3, 3u);
    check_bop(float, power, i4, 3u);
    check_bop(float, power, i5, 3u);
    check_bop(float, power, i6, 3u);
    check_bop(float, power, i7, 3u);
    check_bop(float, power, i8, 3u);
    check_bop(float, power, i9, 3u);
    check_bop(float, power, i10, 3u);
    check_bop(float, power, i11, 3u);
    check_bop(float, power, i12, 3u);
    check_bop(float, power, i13, 3u);
    check_bop(float, power, i14, 3u);
    check_bop(float, power, i15, 3u);
    check_bop(float, power, oi1, 3u);
    check_bop(float, power, oi2, 3u);
    check_bop(float, power, oi3, 3u);
    check_bop(float, power, oi4, 3u);
    check_bop(float, power, oi5, 3u);
    check_bop(float, power, oi6, 3u);
    check_bop(float, power, oi7, 3u);
    check_bop(float, power, oi8, 3u);
    check_bop(float, power, oi9, 3u);
    check_bop(float, power, oi10, 3u);
    check_bop(float, power, oi11, 3u);
    check_bop(float, power, oi12, 3u);
    check_bop(float, power, oi13, 3u);
    check_bop(float, power, oi14, 3u);
    check_bop(float, power, oi15, 3u);
    check_bop(float, power, inf, 3u);
    check_bop(float, power, ozero_ninf, 3u);
    check_bop(float, power, ozero_pinf, 3u);
    check_bop(float, power, czero_ninf, 3u);
    check_bop(float, power, czero_pinf, 3u);

    cout << "=====================" << endl;
    check_uop(float, exp, i1);
    check_uop(float, exp, i2);
    check_uop(float, exp, i3);
    check_uop(float, exp, i4);
    check_uop(float, exp, i5);
    check_uop(float, exp, i6);
    check_uop(float, exp, i7);
    check_uop(float, exp, i8);
    check_uop(float, exp, i9);
    check_uop(float, exp, i10);
    check_uop(float, exp, i11);
    check_uop(float, exp, i12);
    check_uop(float, exp, i13);
    check_uop(float, exp, i14);
    check_uop(float, exp, i15);
    check_uop(float, exp, oi1);
    check_uop(float, exp, oi2);
    check_uop(float, exp, oi3);
    check_uop(float, exp, oi4);
    check_uop(float, exp, oi5);
    check_uop(float, exp, oi6);
    check_uop(float, exp, oi7);
    check_uop(float, exp, oi8);
    check_uop(float, exp, oi9);
    check_uop(float, exp, oi10);
    check_uop(float, exp, oi11);
    check_uop(float, exp, oi12);
    check_uop(float, exp, oi13);
    check_uop(float, exp, oi14);
    check_uop(float, exp, oi15);
    check_uop(float, exp, inf);
    check_uop(float, exp, ozero_pinf);
    check_uop(float, exp, ozero_ninf);
    check_uop(float, exp, czero_pinf);
    check_uop(float, exp, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, exp2, i1);
    check_uop(float, exp2, i2);
    check_uop(float, exp2, i3);
    check_uop(float, exp2, i4);
    check_uop(float, exp2, i5);
    check_uop(float, exp2, i6);
    check_uop(float, exp2, i7);
    check_uop(float, exp2, i8);
    check_uop(float, exp2, i9);
    check_uop(float, exp2, i10);
    check_uop(float, exp2, i11);
    check_uop(float, exp2, i12);
    check_uop(float, exp2, i13);
    check_uop(float, exp2, i14);
    check_uop(float, exp2, i15);
    check_uop(float, exp2, oi1);
    check_uop(float, exp2, oi2);
    check_uop(float, exp2, oi3);
    check_uop(float, exp2, oi4);
    check_uop(float, exp2, oi5);
    check_uop(float, exp2, oi6);
    check_uop(float, exp2, oi7);
    check_uop(float, exp2, oi8);
    check_uop(float, exp2, oi9);
    check_uop(float, exp2, oi10);
    check_uop(float, exp2, oi11);
    check_uop(float, exp2, oi12);
    check_uop(float, exp2, oi13);
    check_uop(float, exp2, oi14);
    check_uop(float, exp2, oi15);
    check_uop(float, exp2, inf);
    check_uop(float, exp2, ozero_pinf);
    check_uop(float, exp2, ozero_ninf);
    check_uop(float, exp2, czero_pinf);
    check_uop(float, exp2, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, exp10, i1);
    check_uop(float, exp10, i2);
    check_uop(float, exp10, i3);
    check_uop(float, exp10, i4);
    check_uop(float, exp10, i5);
    check_uop(float, exp10, i6);
    check_uop(float, exp10, i7);
    check_uop(float, exp10, i8);
    check_uop(float, exp10, i9);
    check_uop(float, exp10, i10);
    check_uop(float, exp10, i11);
    check_uop(float, exp10, i12);
    check_uop(float, exp10, i13);
    check_uop(float, exp10, i14);
    check_uop(float, exp10, i15);
    check_uop(float, exp10, oi1);
    check_uop(float, exp10, oi2);
    check_uop(float, exp10, oi3);
    check_uop(float, exp10, oi4);
    check_uop(float, exp10, oi5);
    check_uop(float, exp10, oi6);
    check_uop(float, exp10, oi7);
    check_uop(float, exp10, oi8);
    check_uop(float, exp10, oi9);
    check_uop(float, exp10, oi10);
    check_uop(float, exp10, oi11);
    check_uop(float, exp10, oi12);
    check_uop(float, exp10, oi13);
    check_uop(float, exp10, oi14);
    check_uop(float, exp10, oi15);
    check_uop(float, exp10, inf);
    check_uop(float, exp10, ozero_pinf);
    check_uop(float, exp10, ozero_ninf);
    check_uop(float, exp10, czero_pinf);
    check_uop(float, exp10, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, log, i1);
    check_uop(float, log, i2);
    check_uop(float, log, i5);
    check_uop(float, log, i6);
    check_uop(float, log, i7);
    check_uop(float, log, i8);
    check_uop(float, log, oi1);
    check_uop(float, log, oi2);
    check_uop(float, log, oi5);
    check_uop(float, log, oi6);
    check_uop(float, log, oi7);
    check_uop(float, log, oi8);
    check_uop(float, log, ozero_pinf);

    cout << "=====================" << endl;
    check_uop(float, log2, i1);
    check_uop(float, log2, i2);
    check_uop(float, log2, i5);
    check_uop(float, log2, i6);
    check_uop(float, log2, i7);
    check_uop(float, log2, i8);
    check_uop(float, log2, oi1);
    check_uop(float, log2, oi2);
    check_uop(float, log2, oi5);
    check_uop(float, log2, oi6);
    check_uop(float, log2, oi7);
    check_uop(float, log2, oi8);
    check_uop(float, log2, ozero_pinf);

    cout << "=====================" << endl;
    check_uop(float, log10, i1);
    check_uop(float, log10, i2);
    check_uop(float, log10, i5);
    check_uop(float, log10, i6);
    check_uop(float, log10, i7);
    check_uop(float, log10, i8);
    check_uop(float, log10, oi1);
    check_uop(float, log10, oi2);
    check_uop(float, log10, oi5);
    check_uop(float, log10, oi6);
    check_uop(float, log10, oi7);
    check_uop(float, log10, oi8);
    check_uop(float, log10, ozero_pinf);

    cout << "=====================" << endl;
    check_uop(float, sin, i1);
    check_uop(float, sin, i2);
    check_uop(float, sin, i3);
    check_uop(float, sin, i4);
    check_uop(float, sin, i5);
    check_uop(float, sin, i6);
    check_uop(float, sin, i7);
    check_uop(float, sin, i8);
    check_uop(float, sin, i9);
    check_uop(float, sin, i10);
    check_uop(float, sin, i11);
    check_uop(float, sin, i12);
    check_uop(float, sin, i13);
    check_uop(float, sin, i14);
    check_uop(float, sin, i15);
    check_uop(float, sin, oi1);
    check_uop(float, sin, oi2);
    check_uop(float, sin, oi3);
    check_uop(float, sin, oi4);
    check_uop(float, sin, oi5);
    check_uop(float, sin, oi6);
    check_uop(float, sin, oi7);
    check_uop(float, sin, oi8);
    check_uop(float, sin, oi9);
    check_uop(float, sin, oi10);
    check_uop(float, sin, oi11);
    check_uop(float, sin, oi12);
    check_uop(float, sin, oi13);
    check_uop(float, sin, oi14);
    check_uop(float, sin, oi15);
    check_uop(float, sin, inf);
    check_uop(float, sin, ozero_pinf);
    check_uop(float, sin, ozero_ninf);
    check_uop(float, sin, czero_pinf);
    check_uop(float, sin, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, cos, i1);
    check_uop(float, cos, i2);
    check_uop(float, cos, i3);
    check_uop(float, cos, i4);
    check_uop(float, cos, i5);
    check_uop(float, cos, i6);
    check_uop(float, cos, i7);
    check_uop(float, cos, i8);
    check_uop(float, cos, i9);
    check_uop(float, cos, i10);
    check_uop(float, cos, i11);
    check_uop(float, cos, i12);
    check_uop(float, cos, i13);
    check_uop(float, cos, i14);
    check_uop(float, cos, i15);
    check_uop(float, cos, oi1);
    check_uop(float, cos, oi2);
    check_uop(float, cos, oi3);
    check_uop(float, cos, oi4);
    check_uop(float, cos, oi5);
    check_uop(float, cos, oi6);
    check_uop(float, cos, oi7);
    check_uop(float, cos, oi8);
    check_uop(float, cos, oi9);
    check_uop(float, cos, oi10);
    check_uop(float, cos, oi11);
    check_uop(float, cos, oi12);
    check_uop(float, cos, oi13);
    check_uop(float, cos, oi14);
    check_uop(float, cos, oi15);
    check_uop(float, cos, inf);
    check_uop(float, cos, ozero_pinf);
    check_uop(float, cos, ozero_ninf);
    check_uop(float, cos, czero_pinf);
    check_uop(float, cos, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, tan, i1);
    check_uop(float, tan, i2);
    check_uop(float, tan, i3);
    check_uop(float, tan, i4);
    check_uop(float, tan, i5);
    check_uop(float, tan, i6);
    check_uop(float, tan, i7);
    check_uop(float, tan, i8);
    check_uop(float, tan, i9);
    check_uop(float, tan, i10);
    check_uop(float, tan, i11);
    check_uop(float, tan, i12);
    check_uop(float, tan, i13);
    check_uop(float, tan, i14);
    check_uop(float, tan, i15);
    check_uop(float, tan, oi1);
    check_uop(float, tan, oi2);
    check_uop(float, tan, oi3);
    check_uop(float, tan, oi4);
    check_uop(float, tan, oi5);
    check_uop(float, tan, oi6);
    check_uop(float, tan, oi7);
    check_uop(float, tan, oi8);
    check_uop(float, tan, oi9);
    check_uop(float, tan, oi10);
    check_uop(float, tan, oi11);
    check_uop(float, tan, oi12);
    check_uop(float, tan, oi13);
    check_uop(float, tan, oi14);
    check_uop(float, tan, oi15);
    check_uop(float, tan, inf);
    check_uop(float, tan, ozero_pinf);
    check_uop(float, tan, ozero_ninf);
    check_uop(float, tan, czero_pinf);
    check_uop(float, tan, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, asin, i11);
    check_uop(float, asin, i12);
    check_uop(float, asin, i13);
    check_uop(float, asin, i14);
    check_uop(float, asin, i15);
    check_uop(float, asin, oi11);
    check_uop(float, asin, oi12);
    check_uop(float, asin, oi13);
    check_uop(float, asin, oi14);
    check_uop(float, asin, oi15);

    cout << "=====================" << endl;
    check_uop(float, acos, i11);
    check_uop(float, acos, i12);
    check_uop(float, acos, i13);
    check_uop(float, acos, i14);
    check_uop(float, acos, i15);
    check_uop(float, acos, oi11);
    check_uop(float, acos, oi12);
    check_uop(float, acos, oi13);
    check_uop(float, acos, oi14);
    check_uop(float, acos, oi15);

    cout << "=====================" << endl;
    check_uop(float, atan, i1);
    check_uop(float, atan, i2);
    check_uop(float, atan, i3);
    check_uop(float, atan, i4);
    check_uop(float, atan, i5);
    check_uop(float, atan, i6);
    check_uop(float, atan, i7);
    check_uop(float, atan, i8);
    check_uop(float, atan, i9);
    check_uop(float, atan, i10);
    check_uop(float, atan, i11);
    check_uop(float, atan, i12);
    check_uop(float, atan, i13);
    check_uop(float, atan, i14);
    check_uop(float, atan, i15);
    check_uop(float, atan, oi1);
    check_uop(float, atan, oi2);
    check_uop(float, atan, oi3);
    check_uop(float, atan, oi4);
    check_uop(float, atan, oi5);
    check_uop(float, atan, oi6);
    check_uop(float, atan, oi7);
    check_uop(float, atan, oi8);
    check_uop(float, atan, oi9);
    check_uop(float, atan, oi10);
    check_uop(float, atan, oi11);
    check_uop(float, atan, oi12);
    check_uop(float, atan, oi13);
    check_uop(float, atan, oi14);
    check_uop(float, atan, oi15);
    check_uop(float, atan, inf);
    check_uop(float, atan, ozero_pinf);
    check_uop(float, atan, ozero_ninf);
    check_uop(float, atan, czero_pinf);
    check_uop(float, atan, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, sinh, i1);
    check_uop(float, sinh, i2);
    check_uop(float, sinh, i3);
    check_uop(float, sinh, i4);
    check_uop(float, sinh, i5);
    check_uop(float, sinh, i6);
    check_uop(float, sinh, i7);
    check_uop(float, sinh, i8);
    check_uop(float, sinh, i9);
    check_uop(float, sinh, i10);
    check_uop(float, sinh, i11);
    check_uop(float, sinh, i12);
    check_uop(float, sinh, i13);
    check_uop(float, sinh, i14);
    check_uop(float, sinh, i15);
    check_uop(float, sinh, oi1);
    check_uop(float, sinh, oi2);
    check_uop(float, sinh, oi3);
    check_uop(float, sinh, oi4);
    check_uop(float, sinh, oi5);
    check_uop(float, sinh, oi6);
    check_uop(float, sinh, oi7);
    check_uop(float, sinh, oi8);
    check_uop(float, sinh, oi9);
    check_uop(float, sinh, oi10);
    check_uop(float, sinh, oi11);
    check_uop(float, sinh, oi12);
    check_uop(float, sinh, oi13);
    check_uop(float, sinh, oi14);
    check_uop(float, sinh, oi15);
    check_uop(float, sinh, inf);
    check_uop(float, sinh, ozero_pinf);
    check_uop(float, sinh, ozero_ninf);
    check_uop(float, sinh, czero_pinf);
    check_uop(float, sinh, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, cosh, i1);
    check_uop(float, cosh, i2);
    check_uop(float, cosh, i3);
    check_uop(float, cosh, i4);
    check_uop(float, cosh, i5);
    check_uop(float, cosh, i6);
    check_uop(float, cosh, i7);
    check_uop(float, cosh, i8);
    check_uop(float, cosh, i9);
    check_uop(float, cosh, i10);
    check_uop(float, cosh, i11);
    check_uop(float, cosh, i12);
    check_uop(float, cosh, i13);
    check_uop(float, cosh, i14);
    check_uop(float, cosh, i15);
    check_uop(float, cosh, oi1);
    check_uop(float, cosh, oi2);
    check_uop(float, cosh, oi3);
    check_uop(float, cosh, oi4);
    check_uop(float, cosh, oi5);
    check_uop(float, cosh, oi6);
    check_uop(float, cosh, oi7);
    check_uop(float, cosh, oi8);
    check_uop(float, cosh, oi9);
    check_uop(float, cosh, oi10);
    check_uop(float, cosh, oi11);
    check_uop(float, cosh, oi12);
    check_uop(float, cosh, oi13);
    check_uop(float, cosh, oi14);
    check_uop(float, cosh, oi15);
    check_uop(float, cosh, inf);
    check_uop(float, cosh, ozero_pinf);
    check_uop(float, cosh, ozero_ninf);
    check_uop(float, cosh, czero_pinf);
    check_uop(float, cosh, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, tanh, i1);
    check_uop(float, tanh, i2);
    check_uop(float, tanh, i3);
    check_uop(float, tanh, i4);
    check_uop(float, tanh, i5);
    check_uop(float, tanh, i6);
    check_uop(float, tanh, i7);
    check_uop(float, tanh, i8);
    check_uop(float, tanh, i9);
    check_uop(float, tanh, i10);
    check_uop(float, tanh, i11);
    check_uop(float, tanh, i12);
    check_uop(float, tanh, i13);
    check_uop(float, tanh, i14);
    check_uop(float, tanh, i15);
    check_uop(float, tanh, oi1);
    check_uop(float, tanh, oi2);
    check_uop(float, tanh, oi3);
    check_uop(float, tanh, oi4);
    check_uop(float, tanh, oi5);
    check_uop(float, tanh, oi6);
    check_uop(float, tanh, oi7);
    check_uop(float, tanh, oi8);
    check_uop(float, tanh, oi9);
    check_uop(float, tanh, oi10);
    check_uop(float, tanh, oi11);
    check_uop(float, tanh, oi12);
    check_uop(float, tanh, oi13);
    check_uop(float, tanh, oi14);
    check_uop(float, tanh, oi15);
    check_uop(float, tanh, inf);
    check_uop(float, tanh, ozero_pinf);
    check_uop(float, tanh, ozero_ninf);
    check_uop(float, tanh, czero_pinf);
    check_uop(float, tanh, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, csc, i1);
    check_uop(float, csc, i2);
    check_uop(float, csc, i3);
    check_uop(float, csc, i4);
    check_uop(float, csc, i5);
    check_uop(float, csc, i6);
    check_uop(float, csc, i7);
    check_uop(float, csc, i8);
    check_uop(float, csc, i9);
    check_uop(float, csc, i10);
    check_uop(float, csc, i11);
    check_uop(float, csc, i12);
    check_uop(float, csc, i13);
    check_uop(float, csc, i14);
    check_uop(float, csc, i15);
    check_uop(float, csc, oi1);
    check_uop(float, csc, oi2);
    check_uop(float, csc, oi3);
    check_uop(float, csc, oi4);
    check_uop(float, csc, oi5);
    check_uop(float, csc, oi6);
    check_uop(float, csc, oi7);
    check_uop(float, csc, oi8);
    check_uop(float, csc, oi9);
    check_uop(float, csc, oi10);
    check_uop(float, csc, oi11);
    check_uop(float, csc, oi12);
    check_uop(float, csc, oi13);
    check_uop(float, csc, oi14);
    check_uop(float, csc, oi15);
    check_uop(float, csc, inf);
    check_uop(float, csc, ozero_pinf);
    check_uop(float, csc, ozero_ninf);
    check_uop(float, csc, czero_pinf);
    check_uop(float, csc, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, sec, i1);
    check_uop(float, sec, i2);
    check_uop(float, sec, i3);
    check_uop(float, sec, i4);
    check_uop(float, sec, i5);
    check_uop(float, sec, i6);
    check_uop(float, sec, i7);
    check_uop(float, sec, i8);
    check_uop(float, sec, i9);
    check_uop(float, sec, i10);
    check_uop(float, sec, i11);
    check_uop(float, sec, i12);
    check_uop(float, sec, i13);
    check_uop(float, sec, i14);
    check_uop(float, sec, i15);
    check_uop(float, sec, oi1);
    check_uop(float, sec, oi2);
    check_uop(float, sec, oi3);
    check_uop(float, sec, oi4);
    check_uop(float, sec, oi5);
    check_uop(float, sec, oi6);
    check_uop(float, sec, oi7);
    check_uop(float, sec, oi8);
    check_uop(float, sec, oi9);
    check_uop(float, sec, oi10);
    check_uop(float, sec, oi11);
    check_uop(float, sec, oi12);
    check_uop(float, sec, oi13);
    check_uop(float, sec, oi14);
    check_uop(float, sec, oi15);
    check_uop(float, sec, inf);
    check_uop(float, sec, ozero_pinf);
    check_uop(float, sec, ozero_ninf);
    check_uop(float, sec, czero_pinf);
    check_uop(float, sec, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, cot, i1);
    check_uop(float, cot, i2);
    check_uop(float, cot, i3);
    check_uop(float, cot, i4);
    check_uop(float, cot, i5);
    check_uop(float, cot, i6);
    check_uop(float, cot, i7);
    check_uop(float, cot, i8);
    check_uop(float, cot, i9);
    check_uop(float, cot, i10);
    check_uop(float, cot, i11);
    check_uop(float, cot, i12);
    check_uop(float, cot, i13);
    check_uop(float, cot, i14);
    check_uop(float, cot, i15);
    check_uop(float, cot, oi1);
    check_uop(float, cot, oi2);
    check_uop(float, cot, oi3);
    check_uop(float, cot, oi4);
    check_uop(float, cot, oi5);
    check_uop(float, cot, oi6);
    check_uop(float, cot, oi7);
    check_uop(float, cot, oi8);
    check_uop(float, cot, oi9);
    check_uop(float, cot, oi10);
    check_uop(float, cot, oi11);
    check_uop(float, cot, oi12);
    check_uop(float, cot, oi13);
    check_uop(float, cot, oi14);
    check_uop(float, cot, oi15);
    check_uop(float, cot, inf);
    check_uop(float, cot, ozero_pinf);
    check_uop(float, cot, ozero_ninf);
    check_uop(float, cot, czero_pinf);
    check_uop(float, cot, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, asinh, i1);
    check_uop(float, asinh, i2);
    check_uop(float, asinh, i3);
    check_uop(float, asinh, i4);
    check_uop(float, asinh, i5);
    check_uop(float, asinh, i6);
    check_uop(float, asinh, i7);
    check_uop(float, asinh, i8);
    check_uop(float, asinh, i9);
    check_uop(float, asinh, i10);
    check_uop(float, asinh, i11);
    check_uop(float, asinh, i12);
    check_uop(float, asinh, i13);
    check_uop(float, asinh, i14);
    check_uop(float, asinh, i15);
    check_uop(float, asinh, oi1);
    check_uop(float, asinh, oi2);
    check_uop(float, asinh, oi3);
    check_uop(float, asinh, oi4);
    check_uop(float, asinh, oi5);
    check_uop(float, asinh, oi6);
    check_uop(float, asinh, oi7);
    check_uop(float, asinh, oi8);
    check_uop(float, asinh, oi9);
    check_uop(float, asinh, oi10);
    check_uop(float, asinh, oi11);
    check_uop(float, asinh, oi12);
    check_uop(float, asinh, oi13);
    check_uop(float, asinh, oi14);
    check_uop(float, asinh, oi15);
    check_uop(float, asinh, inf);
    check_uop(float, asinh, ozero_pinf);
    check_uop(float, asinh, ozero_ninf);
    check_uop(float, asinh, czero_pinf);
    check_uop(float, asinh, czero_ninf);

    cout << "=====================" << endl;
    check_uop(float, acosh, i1);
    check_uop(float, acosh, i2);
    check_uop(float, acosh, i5);
    check_uop(float, acosh, i7);
    check_uop(float, acosh, i8);
    check_uop(float, acosh, oi1);
    check_uop(float, acosh, oi2);
    check_uop(float, acosh, oi5);
    check_uop(float, acosh, oi7);
    check_uop(float, acosh, oi8);

    cout << "=====================" << endl;
    check_uop(float, atanh, i10);
    check_uop(float, atanh, i11);
    check_uop(float, atanh, i12);
    check_uop(float, atanh, i13);
    check_uop(float, atanh, i14);
    check_uop(float, atanh, i15);
    check_uop(float, atanh, oi11);
    check_uop(float, atanh, oi12);
    check_uop(float, atanh, oi13);
    check_uop(float, atanh, oi14);
    check_uop(float, atanh, oi15);
}

int main() {
    enable_trace("numerics");
    float_interval_arith();
    float_interval_inf1();
    float_interval_inf2();
    float_interval_trans();
    return has_violations() ? 1 : 0;
}
