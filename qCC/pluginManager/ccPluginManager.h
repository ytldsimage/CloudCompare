#ifndef CCPLUGINMANAGER_H
#define CCPLUGINMANAGER_H

//##########################################################################
//#                                                                        #
//#                              CLOUDCOMPARE                              #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 or later of the License.      #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: CloudCompare project                               #
//#                                                                        #
//##########################################################################

#include <QList>
#include <QObject>

#include "ccPluginInfo.h"

class QAction;
class QActionGroup;
class QMenu;
class QString;
class QToolBar;
class QWidget;

class ccMainAppInterface;
class ccPluginInterface;

//! Plugin manager
class ccPluginManager : public QObject
{
	Q_OBJECT
	
public:
	ccPluginManager( ccMainAppInterface *appInterface, QWidget *parent );
	~ccPluginManager();
	
	void	init( const ccPluginInterfaceList &plugins );
	
	QMenu	*pluginMenu() const;
	QMenu	*shaderAndFilterMenu() const;
	
	QToolBar *mainPluginToolbar();
	QList<QToolBar *> &additionalPluginToolbars();
	QAction *actionShowMainPluginToolbar();

	QToolBar *glFiltersToolbar();
	QAction *actionShowGLFilterToolbar();
		
	void	updateMenus();
	void	handleSelectionChanged();

	void	showAboutDialog() const;
	
private:
	void	setupActions();
	void	setupMenus();
	void	setupToolbars();
	
	void	enableGLFilter();
	void	disableGLFilter();
	
	QWidget	*m_parentWidget;	// unfortunately we need this when creating new menus & toolbars
	
	ccMainAppInterface *m_appInterface;
	
	QMenu	*m_pluginMenu;
	QMenu	*m_glFilterMenu;
	
	QAction *m_actionRemoveFilter;	
	QActionGroup m_glFilterActions;
	
	QList<ccPluginInterface *> m_plugins;	
	
	QToolBar *m_mainPluginToolbar;	// if a plugin only has one action it goes here
	QList<QToolBar *> m_additionalPluginToolbars;	// if a plugin has multiple actions it gets its own toolbar
	QAction	*m_showPluginToolbar;
	
	QToolBar *m_glFiltersToolbar;
	QAction	*m_showGLFilterToolbar;
};

#endif
