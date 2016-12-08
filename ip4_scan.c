/*
 * ip4_scan.c: This file is part of the `djbdns' project, originally
 * written by Dr. D J Bernstein and later released under public-domain since
 * late December 2007 (http://cr.yp.to/distributors.html).
 *
 * Copyright (C) 2009 - 2013 Prasad J Pandit
 *
 * This program is a free software; you can redistribute it and/or modify
 * it under the terms of GNU General Public License as published by Free
 * Software Foundation; either version 2 of the license or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * of FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "ip4.h"
#include "scan.h"

unsigned int
ip4_scan (const char *s, char ip[4])
{
    unsigned long u = 0;
    unsigned int i = 0, j = 0, len = 0;

    while (j < 4)
    {
        i = scan_ulong (s, &u);
        if (!i)
            return 0;
        ip[j++] = u;

        s += i;
        len += i;
        if (j == 4)
            break;
        if (*s != '.')
            return 0;
        ++s;
        ++len;
    }

    return len;
}
