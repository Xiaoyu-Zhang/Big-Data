#include <algorithm>
#include <limits>
#include <string>
#include <sstream>

#include "hadoop/Pipes.hh"
#include "hadoop/TemplateFactory.hh"
#include "hadoop/StringUtils.hh"

using namespace std;

class statisticMapper: public HadoopPipes::Mapper {
public:
	// constructor: does nothing
	statisticMapper(HadoopPipes::TaskContext& context) {
	};

	void map(HadoopPipes::MapContext& context) {
		string line = context.getInputValue();
		vector< string > words = HadoopUtils::splitString( line, "," );
		context.emit("Time", words[1]);
	};
};

class statisticReducer: public HadoopPipes::Reducer {
public:

	statisticReducer(HadoopPipes::TaskContext& context) {
	};

	// reduce function
	void reduce(HadoopPipes::ReduceContext& context) {
		float MEAN = 0.0;
		float MEAN_SQUARE = 0.0;
		int index = 0;

		while (context.nextValue()) {
			float temp = HadoopUtils::toFloat(context.getInputValue());
			MEAN += temp;
			MEAN_SQUARE += temp * temp;
			index =index+1;
		}

		MEAN = MEAN / float(index);
		MEAN_SQUARE = MEAN_SQUARE / float(index);
		float VARIANCE = MEAN_SQUARE - MEAN * MEAN;

		//convert float to string
		stringstream mean;
		mean<<MEAN;
		string mean_string=mean.str();
		stringstream variance;
		variance<<VARIANCE;
		string variance_string=variance.str();

		//output result
		context.emit("MEAN", mean_string);
		context.emit("VARIANCE", variance_string);
		context.emit("Number of Input", HadoopUtils::toString( index ));

	};
};

int main(int argc, char *argv[]) {
	return HadoopPipes::runTask(
			HadoopPipes::TemplateFactory<statisticMapper, statisticReducer>());
}
