/* Copyright 2021 Trevor Elliott
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "tightyl.h"

// Ignore the blank parts of the matrix, as they're used for left-side detection. Without this, there will be a constant
// keypress registered.
const matrix_row_t matrix_mask[MATRIX_ROWS] = {
//  87654321
  0b00111111,
  0b00111111,
  0b00111111,
  0b00011111,
  0b00111111,
  0b00111111,
  0b00111111,
  0b00011111,
};
