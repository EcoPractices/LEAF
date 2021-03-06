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


#pragma once

// --- LEAF Includes --- //
#include <leaf/open/Common.h>

namespace leaf
{
namespace wrapper
{
namespace weru
{

#ifndef SWIG

///
std::string CalTbl();

///
std::string HrvTbl();

///
bool CreateCalTbl(
    std::string const& tableName );

///
bool CreateHrvTbl(
    std::string const& tableName );

#endif //SWIG

///
namespace Rfd
{
enum File
{
    CLIMATE,
    WIND,
    MANAGEMENT,
    SOIL
};
}

} //end weru
} //end wrapper
} //end leaf
