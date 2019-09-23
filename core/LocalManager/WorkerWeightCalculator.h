§§/*
§§Copyright 2017-2019 Siemens AG
§§
§§Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
§§
§§The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
§§
§§THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
§§
§§Author(s): Abian Blome, Thomas Riedmaier
§§*/
§§
§§#pragma once
§§#include "StatusOfInstance.h"
§§
§§class LMDatabaseManager;
§§class WorkerWeightCalculator
§§{
§§public:
§§	WorkerWeightCalculator(LMDatabaseManager* dbManager, std::string location);
§§	~WorkerWeightCalculator();
§§
§§	void updateStatusInformation();
§§	std::vector<StatusOfInstance> getGeneratorStatus();
§§	std::vector<StatusOfInstance> getEvaluatorStatus();
§§
§§private:
§§	uint32_t calculateGeneratorWeight(StatusOfInstance status);
§§	uint32_t calculateEvaluatorWeight(StatusOfInstance status);
§§
§§	LMDatabaseManager* m_dbManager;
§§	std::vector<StatusOfInstance> m_generatorStatus;
§§	std::vector<StatusOfInstance> m_evaluatorStatus;
§§	std::string m_location;
§§};
