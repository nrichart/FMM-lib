/*
  Copyright 2015 - UVSQ
  Authors list: Nathalie Möller, Eric Petit

  This file is part of the FMM-lib.

  FMM-lib is free software: you can redistribute it and/or modify it under the
  terms of the GNU Lesser General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later version.

  FMM-lib is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
  PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License along with
  the FMM-lib. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FMM_TOOLS_HPP
#define FMM_TOOLS_HPP

#include "types.hpp"
#include <string>
#include <iostream>
#include <fstream> 
#include <cmath>

using namespace std;

void announce_axis(string axis, int rank);
void displayHexa2Dim (string info, ui64 ** tab, int dim1, int dim2);
void displayDiff (string info, int * tab, int size);
void displayMpiMSG (int source, int tag);



void verbose(int rank, string message);


/** templates **/
template<typename T>
void displayTab(string info, T * tab, int size, ostream & out=cout)
{
	out << info << endl;
	for (int i=0; i<size; i++)
		out << std::dec << "[" << i << "]" << tab[i] << "  ";
	out << endl;
}


/** DUMP BUFFERS **/
template<typename T>
void dumpBuffer(int rank, T * buffer, int size, string fileName, string message)
{
	string file = "output/" + fileName + "_" + to_string(rank);
	ofstream out;
	out.open (file, std::ofstream::out | std::ofstream::app);
	
	out << message << endl;
	for (int i=0; i<size; i++)
		if (buffer[i])
			out << buffer[i] << "\n";
	out << endl;
	
	out.close();
}

/** DUMP TREE **/
void dump_tree_init(int rank);
void dump_tree_add_child(int rank, int64_t parent, int64_t child, int nbParticles);
void dump_tree_close_file(int rank);

#endif
