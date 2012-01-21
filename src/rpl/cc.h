/**********************************************************************
 * Copyright (C) 2012 Ricardo Martins                                 *
 **********************************************************************
 * This library is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU Lesser General Public License *
 * as published by the Free Software Foundation; either version 2.1   *
 * of the License, or (at your option) any later version.             *
 *                                                                    *
 * This library is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *
 * Lesser General Public License for more details.                    *
 *                                                                    *
 * You should have received a copy of the GNU Lesser General Public   *
 * License along with this library; if not, write to the Free         *
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,        *
 * Boston, MA 02110-1301 USA                                          *
 **********************************************************************
 * This header identifies the C compiler being used.                  *
 **********************************************************************/

#ifndef RPL_CC_H_INCLUDED_
#define RPL_CC_H_INCLUDED_

/* Intel compiler. */
#  if defined(__INTEL_COMPILER)
#    define RPL_CC_INTEL

/* Sun Studio/Sun Pro compiler. */
#  elif defined(__SUNPRO_C)
#    define RPL_CC_SUN

/* Clang compiler. */
#  elif defined(__clang__)
#    define RPL_CC_CLANG

/* GNU Compiler Collection. */
#  elif defined(__GNUC__)
#    define RPL_CC_GNU

/* Microsoft compiler. */
#  elif defined(_MSC_VER)
#    define RPL_CC_MICROSOFT

/* Unknown compiler. */
#  else
#    define RPL_CC_UNKNOWN

#  endif

#endif
