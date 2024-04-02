#include "Approvals.h"
#define APPROVALS_CATCH2_V3
#include <ApprovalTests.hpp>
#include <gol/gol.hpp>
#include <string>

using ApprovalTests::Approvals;
using gol::something_really_obscure;
using std::back_inserter;
using std::string;
using std::to_string;
using std::transform;
using std::vector;

TEST_CASE("foo snapshot test example") {
    Approvals::verify(something_really_obscure(3.14));
}

TEST_CASE("foo snapshot test example, multiple inputs") {
    vector<double> inputs = {4., 8., 15., 16., 23., 42.};
    vector<double> outputs;
    transform(
        inputs.begin(),
        inputs.end(),
        back_inserter(outputs),
        something_really_obscure
    );
    Approvals::verifyAll(outputs);
}

TEST_CASE("foo snapshot test example, converter") {
    vector<double> inputs = {4., 8., 15., 16., 23., 42.};
    vector<double> outputs;
    transform(
        inputs.begin(),
        inputs.end(),
        back_inserter(outputs),
        something_really_obscure
    );

    size_t i = 0;
    auto converter = [&](int e, std::ostream& s) {
        s << "[" << inputs[i] << "] = " << e;
        ++i;
    };
    Approvals::verifyAll("This is the header", outputs, converter);
}
