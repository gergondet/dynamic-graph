// Copyright 2010, François Bleibel, Thomas Moulard, Olivier Stasse,
// JRL, CNRS/AIST.
//
// This file is part of dynamic-graph.
// dynamic-graph is free software: you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation, either version 3 of
// the License, or (at your option) any later version.
//
// dynamic-graph is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// dynamic-graph. If not, see <http://www.gnu.org/licenses/>.

#include <dynamic-graph/interpreter.h>
#include <dynamic-graph/functions.h>
#include <dynamic-graph/plugin-loader.h>
#include <dynamic-graph/factory.h>
#include <dynamic-graph/debug.h>
#include <dynamic-graph/entity.h>
#include <dynamic-graph/signal.h>
#include <dynamic-graph/exception-signal.h>

#ifdef WIN32
#include <Windows.h>
#endif

#include <fstream>
using namespace std;
using namespace dynamicgraph;

extern "C" {
   ShellFunctionRegisterer regFun1
   ( "try",boost::bind(ShellFunctions::cmdTry,_1,_2,_3) );
   ShellFunctionRegisterer regFun2
   ( "loadPlugins",boost::bind(ShellFunctions::cmdLoadPlugins,_1,_2,_3) );
   ShellFunctionRegisterer regFun3
    ( "displayPlugins",boost::bind(ShellFunctions::cmdDisplayPlugins,_1,_2,_3) );
    ShellFunctionRegisterer regFun4
    ( "factory",boost::bind(ShellFunctions::cmdDisplayFactory,_1,_2,_3) );
    ShellFunctionRegisterer regFun5
    ( "#",boost::bind(ShellFunctions::cmdCommentary,_1,_2,_3) );
    ShellFunctionRegisterer regFun7
    ( "unplug",boost::bind(ShellFunctions::cmdUnplug,_1,_2,_3) );
    ShellFunctionRegisterer regFun8
    ( "clearPlugin",boost::bind(ShellFunctions::cmdClearPlugin,_1,_2,_3) );
    ShellFunctionRegisterer regFun9
    ( "signalTime",boost::bind(ShellFunctions::cmdSignalTime,_1,_2,_3) );
    ShellFunctionRegisterer regFun10
    ( "synchro",boost::bind(ShellFunctions::cmdSynchroSignal,_1,_2,_3) );
    ShellFunctionRegisterer regFun11
    ( "echo",boost::bind(ShellFunctions::cmdEcho,_1,_2,_3) );
    ShellFunctionRegisterer regFun12
    ( "copy",boost::bind(ShellFunctions::cmdCopy,_1,_2,_3) );
    ShellFunctionRegisterer regFun13
    ( "freeze",boost::bind(ShellFunctions::cmdFreeze,_1,_2,_3) );
    ShellFunctionRegisterer regFun13b
    ( "squeeze",boost::bind(ShellFunctions::cmdSqueeze,_1,_2,_3) );
    ShellFunctionRegisterer regFun14
    ( "debugtrace",boost::bind(ShellFunctions::cmdEnableTrace,_1,_2,_3) );
    ShellFunctionRegisterer regFun15
    ( "prompt",boost::bind(ShellFunctions::cmdSetPrompt,_1,_2,_3) );
    ShellFunctionRegisterer regFun16
    ( "sleep",boost::bind(ShellFunctions::cmdSleep,_1,_2,_3) );
    ShellFunctionRegisterer regFun17
    ( "beep",boost::bind(ShellFunctions::cmdBeep,_1,_2,_3) );
    ShellFunctionRegisterer regFun19
    ( "completion",boost::bind(ShellFunctions::cmdCompletionList,_1,_2,_3) );

}

