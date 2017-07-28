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
#include <leaf/wrapper/weru/soil/IFC.h>

using namespace leaf::open;

namespace leaf
{
namespace wrapper
{
namespace weru
{
namespace soil
{

////////////////////////////////////////////////////////////////////////////////
IFC::IFC(
    jobject const& o )
    :
    java::lang::Object( o )
{
    ;
}
////////////////////////////////////////////////////////////////////////////////
IFC::IFC(
    NASIS const& nasis )
    :
    java::lang::Object(
        java::NewObject( GetJclass(), GetJmid( "<init>" ), nasis.Jobj() ) )
{
    ;
}
////////////////////////////////////////////////////////////////////////////////
IFC::~IFC()
{
    ;
}
////////////////////////////////////////////////////////////////////////////////
void IFC::WriteNewIfc(
    java::lang::String const& filePath ) const
{
    java::CallMethod< void >(
        m_jobject, GetJmid( "writeNewIfc" ), filePath.Jobj() );
}
////////////////////////////////////////////////////////////////////////////////
jclass const& IFC::GetJclass()
{
    static jclass const clazz = java::FindClass( "usda/weru/soil/IFC" );
    return clazz;
}
////////////////////////////////////////////////////////////////////////////////
jmethodID const& IFC::GetJmid(
    std::string const& name )
{
    static java::JMIDMAP const jmidMap = boost::assign::map_list_of
        ( "<init>",
          java::GetMethodID(
              GetJclass(), "<init>",
              "(Lusda/weru/soil/NASIS;)V" ) )
        ( "writeNewIfc",
          java::GetMethodID(
              GetJclass(), "writeNewIfc",
              "(Ljava/lang/String;)V" ) );

    java::JMIDMAP::const_iterator itr = jmidMap.find( name );
    return itr->second;
}
////////////////////////////////////////////////////////////////////////////////

} //end soil
} //end weru
} //end wrapper
} //end leaf
