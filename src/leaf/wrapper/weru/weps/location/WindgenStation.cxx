// Copyright 2017 Battelle Energy Alliance, LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.



// --- LEAF Includes --- //
#include <leaf/wrapper/weru/weps/location/WindgenStation.h>

namespace leaf
{
namespace wrapper
{
namespace weru
{
namespace weps
{
namespace location
{

////////////////////////////////////////////////////////////////////////////////
WindgenStation::WindgenStation(
    jobject const& o )
    :
    Station( o )
{
    ;
}
////////////////////////////////////////////////////////////////////////////////
WindgenStation::~WindgenStation()
{
    ;
}
////////////////////////////////////////////////////////////////////////////////
Station::Type WindgenStation::GetType() const
{
    return Station::WINDGEN;
}
////////////////////////////////////////////////////////////////////////////////
long WindgenStation::GetWBan() const
{
    //This conversion may be incorrect
    return static_cast< long >(
        java::CallMethod< jlong >( m_jobject, GetJmid( "getWBan" ) ) );
}
////////////////////////////////////////////////////////////////////////////////
jclass const& WindgenStation::GetJclass()
{
    static jclass const clazz =
        java::FindClass( "usda/weru/weps/location/WindgenStation" );
    return clazz;
}
////////////////////////////////////////////////////////////////////////////////
jmethodID const& WindgenStation::GetJmid(
    std::string const& name )
{
    static java::JMIDMAP const jmidMap = boost::assign::map_list_of
        ( "getWBan",
          java::GetMethodID(
              GetJclass(), "getWBan",
              "()J" ) );

    java::JMIDMAP::const_iterator itr = jmidMap.find( name );
    return itr->second;
}
////////////////////////////////////////////////////////////////////////////////

} //end location
} //end weps
} //end weru
} //end wrapper
} //end leaf
