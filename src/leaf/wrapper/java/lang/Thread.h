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
#include <leaf/wrapper/java/lang/ClassLoader.h>
#include <leaf/wrapper/java/lang/Enum.h>
#include <leaf/wrapper/java/lang/Object.h>
#include <leaf/wrapper/java/lang/StackTraceElement.h>
#include <leaf/wrapper/java/lang/String.h>

#include <leaf/wrapper/java/util/Array.h>

namespace leaf
{
namespace wrapper
{
namespace java
{

namespace util
{
template< typename K, typename V, bool keyIsObject, bool valIsObject >
class Map;
}

namespace lang
{

class Thread;
typedef boost::shared_ptr< Thread > ThreadPtr;

class LEAF_JAVA_EXPORTS Thread : public Object
{
public:
    ///
    Thread(
        jobject const& o );

    ///
    virtual ~Thread();

    ///
    static ThreadPtr CurrentThread();

    ///
    static boost::shared_ptr<
        util::Map< Thread, util::Array< StackTraceElement >, true, true > >
    GetAllStackTraces();

    ///
    ClassLoaderPtr GetContextClassLoader() const;

    ///
    long GetId() const;

    ///
    StringPtr GetName() const;

    ///
    EnumPtr GetState() const;

    ///
    void Join() const;

    ///
    void SetContextClassLoader(
        ClassLoader const& cl );

    ///
    StringPtr ToString() const;

    ///
    static void WaitForEDT();

    ///
    static jclass const& GetJclass();

protected:

private:
    ///
    static jmethodID const& GetJmid(
        std::string const& name );

};

} //end lang
} //end java
} //end wrapper
} //end leaf
