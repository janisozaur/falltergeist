/*
 * Copyright 2012-2014 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// C++ standard includes

// Falltergeist includes
#include "../../Engine/Graphics/AnimatedPalette.h"

// Third party includes

namespace Falltergeist
{

AnimatedPalette::AnimatedPalette()
{
    _monitorsPalette = new unsigned int[5];
    _monitorsPalette[0] = 0x6B6B6FFF; _monitorsPalette[1] = 0x63677FFF; _monitorsPalette[2] = 0x576B8FFF; _monitorsPalette[3] = 0x0093A3FF; _monitorsPalette[4] = 0x6BBBFFFF;

    _slimePalette = new unsigned int[4];
    _slimePalette[0] = 0x006C00FF; _slimePalette[1] = 0x0B7307FF; _slimePalette[2] = 0x1B7B0FFF; _slimePalette[3] = 0x2B831BFF;

    _shorePalette = new unsigned int[6];
    _shorePalette[0] = 0x533F2BFF; _shorePalette[1] = 0x4B3B2BFF; _shorePalette[2] = 0x433727FF; _shorePalette[3] = 0x3F3327FF; _shorePalette[4] = 0x372F23FF; _shorePalette[5] = 0x332B23FF;

    _fireSlowPalette = new unsigned int[5];
    _fireSlowPalette[0] = 0xFF0000FF; _fireSlowPalette[1] = 0xD70000FF; _fireSlowPalette[2] = 0x932B0BFF; _fireSlowPalette[3] = 0xFF7700FF; _fireSlowPalette[4] = 0xFF3B00FF;

    _fireFastPalette = new unsigned int[5];
    _fireFastPalette[0] = 0x470000FF; _fireFastPalette[1] = 0x7B0000FF; _fireFastPalette[2] = 0xB30000FF; _fireFastPalette[3] = 0x7B0000FF; _fireFastPalette[4] = 0x470000FF;

    _blinkingRed = 252;
}

AnimatedPalette::~AnimatedPalette()
{
    delete [] _monitorsPalette;
    delete [] _slimePalette;
    delete [] _shorePalette;
    delete [] _fireSlowPalette;
    delete [] _fireFastPalette;
}




unsigned int AnimatedPalette::color(unsigned char index, unsigned char counter)
{
    if (index >= 233 && index <= 237) // monitors
    {
        unsigned int newIndex = (index - 233 + counter)%5;
        return _monitorsPalette[newIndex];
    }

    if (index >= 229 && index <= 232) // slime
    {
        unsigned int newIndex = (index - 229 + counter)%4;
        return _slimePalette[newIndex];
    }

    if (index >= 248 && index <= 253) // shore
    {
        unsigned int newIndex = (index - 248 + counter)%6;
        return _shorePalette[newIndex];
    }

    if (index >= 238 && index <= 242) // slow fire
    {
        unsigned int newIndex = (index - 238 + counter)%5;
        return _fireSlowPalette[newIndex];
    }

    if (index >= 243 && index <= 247) // fast fire
    {
        unsigned int newIndex = (index - 243 + counter)%5;
        return _fireFastPalette[newIndex];
    }

    if (index == 254) // blinking red
    {
        return ((((counter*4)) << 24)) | 0x000000FF;
    }

    return 0x00000000;
}



}
