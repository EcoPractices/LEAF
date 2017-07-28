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

#include <leaf/wrapper/java/util/Array.h>

namespace leaf
{
namespace wrapper
{
namespace java
{
namespace awt
{

class Window;
typedef boost::shared_ptr< Window > WindowPtr;

class LEAF_JAVA_EXPORTS Window : public lang::Object
{
public:
    ///
    Window(
        jobject const& o );

    ///
    virtual ~Window();

    ///
    boost::shared_ptr< util::Array< Window, true > > GetOwnedWindows() const;

    ///
    static jclass const& GetJclass();

protected:

private:
    ///
    static jmethodID const& GetJmid(
        std::string const& name );

};

} //end awt
} //end java
} //end wrapper
} //end leaf
