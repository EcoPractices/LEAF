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
#include <leaf/wrapper/weru/util/LoadingContext.h>

namespace leaf
{
namespace wrapper
{
namespace weru
{
namespace util
{

////////////////////////////////////////////////////////////////////////////////
LoadingContext::~LoadingContext()
{
    ;
}
////////////////////////////////////////////////////////////////////////////////
void LoadingContext::Enter()
{
    java::CallStaticMethod< void >( GetJclass(), GetJmid( "enter" ) );
}
////////////////////////////////////////////////////////////////////////////////
void LoadingContext::Exit()
{
    java::CallStaticMethod< void >( GetJclass(), GetJmid( "exit" ) );
}
////////////////////////////////////////////////////////////////////////////////
bool LoadingContext::IsLoading()
{
    return ( java::CallStaticMethod< jboolean >(
        GetJclass(), GetJmid( "isLoading" ), true ) != JNI_FALSE );
}
////////////////////////////////////////////////////////////////////////////////
jclass const& LoadingContext::GetJclass()
{
    static jclass const clazz =
        java::FindClass( "usda/weru/util/LoadingContext" );
    return clazz;
}
////////////////////////////////////////////////////////////////////////////////
jmethodID const& LoadingContext::GetJmid(
    std::string const& name )
{
    static java::JMIDMAP const jmidMap = boost::assign::map_list_of
        ( "enter",
          java::GetStaticMethodID(
              GetJclass(), "enter",
              "()V" ) )
        ( "exit",
          java::GetStaticMethodID(
            GetJclass(), "exit",
            "()V" ) )
        ( "isLoading",
          java::GetStaticMethodID(
            GetJclass(), "isLoading",
            "(Z)Z" ) );

    java::JMIDMAP::const_iterator itr = jmidMap.find( name );
    return itr->second;
}
////////////////////////////////////////////////////////////////////////////////

} //end util
} //end weru
} //end wrapper
} //end leaf
