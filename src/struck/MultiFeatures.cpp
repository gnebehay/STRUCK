/* 
 * Struck: Structured Output Tracking with Kernels
 * 
 * Code to accompany the paper:
 *   Struck: Structured Output Tracking with Kernels
 *   Sam Hare, Amir Saffari, Philip H. S. Torr
 *   International Conference on Computer Vision (ICCV), 2011
 * 
 * Copyright (C) 2011 Sam Hare, Oxford Brookes University, Oxford, UK
 * 
 * This file is part of Struck.
 * 
 * Struck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Struck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Struck.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "MultiFeatures.h"

using namespace Eigen;
using namespace std;

MultiFeatures::MultiFeatures(const vector<Features*>& features) :
	m_features(features)
{
	int d = 0;
	for (int i = 0; i < (int)features.size(); ++i)
	{
		d += features[i]->GetCount();
	}
	SetCount(d);
}

void MultiFeatures::UpdateFeatureVector(const Sample& s)
{
	int start = 0;
	for (int i = 0; i < (int)m_features.size(); ++i)
	{
		int n =  m_features[i]->GetCount();
		m_featVec.segment(start, n) = m_features[i]->Eval(s);
		start += n;
	}
}
