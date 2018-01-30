/*
 * Copyright (c) 2015-2017 Meltytech, LLC
 * Author: Brian Matherly <code@brianmatherly.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef AUDIOPEAKMETERSCOPEWIDGET_H
#define AUDIOPEAKMETERSCOPEWIDGET_H

#include "scopewidget.h"
#include <QMutex>
#include <QImage>
#include <QVector>
#include <MltFilter.h>

class AudioMeterWidget;

class AudioPeakMeterScopeWidget Q_DECL_FINAL : public ScopeWidget
{
    Q_OBJECT
    
public:
    explicit AudioPeakMeterScopeWidget();
    ~AudioPeakMeterScopeWidget();
    QString getTitle() Q_DECL_OVERRIDE;
    void setOrientation(Qt::Orientation orientation) Q_DECL_OVERRIDE;

private:
    // Functions run in scope thread.
    void refreshScope(const QSize& size, bool full) Q_DECL_OVERRIDE;

    // Members accessed by scope thread.
    Mlt::Filter* m_filter;

    // Members accessed by GUI thread.
    AudioMeterWidget* m_audioMeter;
    Qt::Orientation m_orientation;
    int m_channels;

private slots:
    void recalcSize();
};

#endif // AUDIOPEAKMETERSCOPEWIDGET_H
