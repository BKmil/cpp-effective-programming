#include "CError.h"
#include "CResultSaver.h"

template <typename T>
void CResultSaver::save(const CResult<T, CError>& result, const std::string& filename) {
    std::ofstream out(filename.c_str());
    if (!out) {
        return;
    }
    if (result.bIsSuccess()) {
        out << "Success" << std::endl;
    } else {
        std::vector<CError*>& errors = result.getErrors();
        for (size_t i = 0; i < errors.size(); i++) {
            out<< "Error: "<<errors[i]->sGetDescription() << std::endl;
        }
    }
    out.close();
}
