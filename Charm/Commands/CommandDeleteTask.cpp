/*
  CommandDeleteTask.cpp

  This file is part of Charm, a task-based time tracking application.

  Copyright (C) 2007-2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com

  Author: Mirko Boehm <mirko.boehm@kdab.com>
  Author: Frank Osterfeld <frank.osterfeld@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CommandDeleteTask.h"
#include "ViewHelpers.h"

#include "Core/CharmConstants.h"
#include "Core/ControllerInterface.h"

CommandDeleteTask::CommandDeleteTask( const Task& task, QObject* parent )
    : CharmCommand( tr("Delete Task"), parent )
    , m_task( task )
    , m_success( false )
{
}

CommandDeleteTask::~CommandDeleteTask()
{
}

bool CommandDeleteTask::prepare()
{
    return true;
}

bool CommandDeleteTask::execute( ControllerInterface* controller )
{
    m_success = controller->deleteTask( m_task );
    return m_success;
}

bool CommandDeleteTask::finalize()
{
    if ( !m_success ) {
        showInformation( tr( "Unable to delete task" ), tr( "Deleting the task failed" ) );
    }
    return m_success;
}

#include "moc_CommandDeleteTask.cpp"
