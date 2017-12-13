#pragma once
#include<lol/base_def.hpp> 
namespace lol {
  struct CollectionsLcdsRentalUpdateNotification { 
    json data;
    std::string inventoryType; 
  };
  void to_json(json& j, const CollectionsLcdsRentalUpdateNotification& v) {
  j["data"] = v.data; 
  j["inventoryType"] = v.inventoryType; 
  }
  void from_json(const json& j, CollectionsLcdsRentalUpdateNotification& v) {
  v.data = j.at("data").get<json>(); 
  v.inventoryType = j.at("inventoryType").get<std::string>(); 
  }
}