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
#include <leaf/wrapper/java/lang/Object.h>

namespace leaf
{
namespace wrapper
{
namespace java
{
namespace util
{

///
template< typename E,
    bool isObject = boost::is_base_of< lang::Object, E >::value >
class Iterator : public lang::Object
{
public:

    ///
    typedef typename boost::shared_ptr< E > TypeSPtr;
    typedef typename boost::shared_ptr< Iterator< E > > SPtr;
    typedef typename leaf::util::Select<
        isObject, TypeSPtr, E >::Result ElementType;

    ///
    Iterator(
        jobject const& o )
        :
        lang::Object( o )
    {
        ;
    }

    ///
    virtual ~Iterator()
    {
        ;
    }

    ///
    bool HasNext() const
    {
        return ( java::CallMethod< jboolean >(
            m_jobject, GetJmid( "hasNext" ) ) != JNI_FALSE );
    }

    ///
    ElementType Next() const
    {
        return Next( leaf::util::Int2Type< isObject >() );
    }

    ///
    static jclass const& GetJclass()
    {
        static jclass const clazz = java::FindClass( "java/util/Iterator" );
        return clazz;
    }

protected:

private:
    ///
    ElementType Next(
        leaf::util::Int2Type< true > ) const
    {
        return Create< E >(
            java::CallMethod< jobject >( m_jobject, GetJmid( "next" ) ) );
    }

    ///
    ElementType Next(
        leaf::util::Int2Type< false > ) const
    {
        return java::CallMethod< E >( m_jobject, GetJmid( "next" ) );
    }

    ///
    static jmethodID const& GetJmid(
        std::string const& name )
    {
        static java::JMIDMAP const jmidMap = boost::assign::map_list_of
            ( "hasNext",
              java::GetMethodID(
                  GetJclass(), "hasNext",
                  "()Z" ) )
            ( "next",
              java::GetMethodID(
                  GetJclass(), "next",
                  "()Ljava/lang/Object;" ) );

        java::JMIDMAP::const_iterator itr = jmidMap.find( name );
        return itr->second;
    }

};

} //end util
} //end java
} //end wrapper
} //end leaf
