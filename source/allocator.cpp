////////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////
#ifdef __OTSERV_ALLOCATOR__
#include "otpch.h"
#include "allocator.h"

void* operator new[](size_t bytes, int32_t dummy)
{
	return malloc(bytes);
}

void operator delete(void* p, int32_t dummy)
{
	std::free(p);
}

void operator delete[](void* p, int32_t dummy)
{
	std::free(p);
}

#ifdef __OTSERV_ALLOCATOR_STATS__
void allocatorStatsThread(void* a)
{
	while(true)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(30000));
		PoolManager::getInstance()->dumpStats();
	}
}
#endif
#endif
