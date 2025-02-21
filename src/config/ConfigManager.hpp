#pragma once

#include "../helpers/Log.hpp"

#include <hyprlang.hpp>

#include <vector>
#include <memory>
#include <unordered_map>

class CConfigManager {
  public:
    CConfigManager();
    void         init();
    void* const* getValuePtr(const std::string& name);

    struct SWidgetConfig {
        std::string                               type;
        std::string                               monitor;

        std::unordered_map<std::string, std::any> values;
    };

    std::vector<SWidgetConfig> getWidgetConfigs();

  private:
    Hyprlang::CConfig m_config;
};

inline std::unique_ptr<CConfigManager> g_pConfigManager;
