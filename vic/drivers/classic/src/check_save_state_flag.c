/******************************************************************************
 * @section DESCRIPTION
 *
 * Function to check whether model state should be saved for the current
 * time step
 *
 * @section LICENSE
 *
 * The Variable Infiltration Capacity (VIC) macroscale hydrological model
 * Copyright (C) 2016 The Computational Hydrology Group, Department of Civil
 * and Environmental Engineering, University of Washington.
 *
 * The VIC model is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *****************************************************************************/

#include <vic_driver_classic.h>

/******************************************************************************
 * @brief   Function to check whether model state should be saved for the
 *          current time step
 *****************************************************************************/
bool
check_save_state_flag(dmy_struct *dmy,
                      size_t      current)
{
    extern global_param_struct global_param;

    if (dmy[current].year == global_param.stateyear &&
        dmy[current].month == global_param.statemonth &&
        dmy[current].day == global_param.stateday &&
        dmy[current].dayseconds == global_param.statesec) {
        return true;
    }
    else {
        return false;
    }
}