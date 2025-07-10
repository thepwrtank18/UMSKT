/**
 * This file is a part of the UMSKT Project
 *
 * Copyleft (C) 2019-2023 UMSKT Contributors (et.al.)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @FileCreated by Neo on 5/26/2023
 * @Maintainer Neo
 */

#ifndef UMSKT_HEADER_H
#define UMSKT_HEADER_H

#include "typedefs.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>

#include <fmt/core.h>
#include <nlohmann/json.hpp>
#include <tinydir.h>

using json = nlohmann::json;

// Simple path class to replace boost::filesystem::path
class Path {
private:
    std::string m_path;
public:
    Path() = default;
    Path(const char* path) : m_path(path) {}
    Path(const std::string& path) : m_path(path) {}
    
    bool empty() const { return m_path.empty(); }
    std::string string() const { return m_path; }
    
    static bool exists(const Path& p) {
        tinydir_file file;
        if (tinydir_file_open(&file, p.string().c_str()) == -1) {
            return false;
        }
        tinydir_file_close(&file);
        return true;
    }
};

#endif //UMSKT_HEADER_H
