/* 
 * Copyright (C) 2006-2013  Music Technology Group - Universitat Pompeu Fabra
 *
 * This file is part of Gaia
 * 
 * Gaia is free software: you can redistribute it and/or modify it under 
 * the terms of the GNU Affero General Public License as published by the Free 
 * Software Foundation (FSF), either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more 
 * details.
 * 
 * You should have received a copy of the Affero GNU General Public License
 * version 3 along with this program.  If not, see http://www.gnu.org/licenses/
 */

/* <copyright entity="UPF">
# UPF. All Right Reserved, http://www.upf.edu/
#
# This source is subject to the Contributor License Agreement of the Essentia project.
# Please see the CLA.txt file available at http://essentia.upf.edu/contribute/
# for more
# information.
#
# THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
# KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
# PARTICULAR PURPOSE.
#
# </copyright>
*/


#ifndef GAIA_ADDFIELDAPPLIER_H
#define GAIA_ADDFIELDAPPLIER_H

#include "applier.h"
#include "../utils.h"

namespace gaia2 {

/**
 * @ingroup appliers
 * AddFieldApplier applier class. Adds the specified fields to the current
 * layout.
 */
class AddFieldApplier : public Applier {
 protected:
  QStringList _real, _string;
  PointLayout _newLayout;
  Point _addedPoint;
  QList<Point> _addedPoints;
  IndexMap _realMap1, _stringMap1, _enumMap1, _realMap2, _stringMap2, _enumMap2;

 public:
  AddFieldApplier(const Transformation& transfo);
  virtual ~AddFieldApplier();

  /**
   * Ownership of resulting point is handed to caller of this function.
   */
  virtual Point* mapPoint(const Point* p) const;

  /**
   * Optimized version so that we don't have to recompute the index mappings
   * for each point.
   */
  DataSet* mapDataSet(const DataSet* dataset) const;


 protected:
  PointLayout mapLayout(const PointLayout& layout) const;

};

} // namespace gaia2

#endif // GAIA_ADDFIELDAPPLIER_H
