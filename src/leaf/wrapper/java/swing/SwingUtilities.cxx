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


// --- LEAF Includes --- //
#include <leaf/wrapper/java/swing/SwingUtilities.h>

namespace leaf
{
namespace wrapper
{
namespace javax
{
namespace swing
{

////////////////////////////////////////////////////////////////////////////////
SwingUtilities::~SwingUtilities()
{
    ;
}
////////////////////////////////////////////////////////////////////////////////
java::awt::FramePtr SwingUtilities::GetSharedOwnerFrame()
{
    return java::lang::Object::Create< java::awt::Frame >(
        java::CallStaticMethod< jobject >(
            GetJclass(), GetJmid( "getSharedOwnerFrame" ) ) );
}
////////////////////////////////////////////////////////////////////////////////
jclass const& SwingUtilities::GetJclass()
{
    static jclass const clazz = java::FindClass( "javax/swing/SwingUtilities" );
    return clazz;
}
////////////////////////////////////////////////////////////////////////////////
jmethodID const& SwingUtilities::GetJmid(
    std::string const& name )
{
    static java::JMIDMAP const jmidMap = boost::assign::map_list_of
        ( "getSharedOwnerFrame",
          java::GetStaticMethodID(
              GetJclass(), "getSharedOwnerFrame",
              "(Ljava/lang/String;)Ljava/lang/String;" ) );

    java::JMIDMAP::const_iterator itr = jmidMap.find( name );
    return itr->second;
}
////////////////////////////////////////////////////////////////////////////////

} //end swing
} //end javax
} //end wrapper
} //end leaf
