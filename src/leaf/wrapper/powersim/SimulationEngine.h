/*************** <auto-copyright.rb BEGIN do not edit this line> **************
 *
 * Copyright 2012-2013 by Ames Laboratory
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 *************** <auto-copyright.rb END do not edit this line> ***************/


#pragma once

// --- LEAF Includes --- //
#include "Common.h"
#include "SimulationEnginePtr.h"
#include "SimulationProjectPtr.h"

namespace leaf
{
namespace wrapper
{
namespace powersim
{

class LEAF_POWERSIM_EXPORTS SimulationEngine
{
public:
    ///Constructor
    SimulationEngine();

    ///Destructor
    ~SimulationEngine();

    ///
    static SimulationEnginePtr Create();

    ///Open a SimulationProject
    SimulationProjectPtr OpenProject(
        std::string const& fileName,
        std::string const& key = "",
        std::string const& password = "",
        bool const& browseForFile = false ) const;

protected:

private:
    ///Restrict copying from copy constructor
    SimulationEngine(
        SimulationEngine const& );

    ///Restrict copying from equal operator
    SimulationEngine& operator=(
        SimulationEngine const& );

    ///
    ATL::CComPtr< ::ISimulationEngine > m_simulationEngine;

};

} //end powersim
} //end wrapper
} //end leaf
