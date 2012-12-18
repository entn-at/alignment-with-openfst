#include "LearningInfo.h"
#include "FstUtils.h"
#include "StringUtils.h"
#include "LatentCrfModel.h"

using namespace fst;
using namespace std;

typedef ProductArc<LogWeight, LogWeight> ProductLogArc;

void ParseParameters(int argc, char **argv, string &textFilename, string &outputFilenamePrefix) {
  assert(argc == 3);
  textFilename = argv[1];
  outputFilenamePrefix = argv[2];
}


int main(int argc, char **argv) {
  // parse arguments
  cout << "parsing arguments" << endl;
  string textFilename, outputFilenamePrefix;
  ParseParameters(argc, argv, textFilename, outputFilenamePrefix);

  // configurations
  LearningInfo learningInfo;
  // block coord 
  learningInfo.optimizationMethod.algorithm = OptAlgorithm::BLOCK_COORD_DESCENT;
  learningInfo.useMaxIterationsCount = true;
  learningInfo.maxIterationsCount = 50;
  learningInfo.useMinLikelihoodDiff = true;
  learningInfo.minLikelihoodDiff = 1;
  learningInfo.optimizationMethod.subOptMethod = new OptMethod();
  learningInfo.optimizationMethod.subOptMethod->lbfgsParams.maxIterations = 50;
  learningInfo.optimizationMethod.subOptMethod->lbfgsParams.memoryBuffer = 500;
  learningInfo.optimizationMethod.subOptMethod->miniBatchSize = 10;

  // train the model
  LatentCrfModel& model = LatentCrfModel::GetInstance(textFilename, outputFilenamePrefix, learningInfo);
  model.Train();
}
