import requests
import json
def get_lat_ln(address,api_key):
    api_req="https://www.mapquestapi.com/geocoding/v1/address?key={}&inFormat=kvp&outFormat=json&location={}&thumbMaps=false".format(api_key,address.replace(' ','+'))
    try:
        resp=requests.get(api_req)
        resp_pl=resp.json()
        # print(resp_pl)
        lat=resp_pl['results'][0]['locations'][0]['latLng']['lat']
        lng=resp_pl['results'][0]['locations'][0]['latLng']['lng']
        return [lat,lng]
    except Exception as e:
        print(e)
        return []

def get_covid_data(lat_lng_arr,api_key):
    cov_dat={"key":api_key,"latlngs":lat_lng_arr}
    print(cov_dat)
    api_req="https://data.geoiq.io/dataapis/v1.0/covid/locationcheck"
    try:
        resp=requests.post(api_req,data=json.dumps(cov_dat))
        return resp.json()
    except Exception as e:
        print(e)
        return []

if __name__=="__main__":
    mapquest_api_key=" bJHReAdr8EyIvZ58KClwxFHmLfeWZOoX"
    coivd_api_key="eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJtYWlsSWRlbnRpdHkiOiJrdW1hcjEyMzU4MTNAZ21haWwuY29tIn0.2z_ZhRavOVEqCVRo0UndNYFp3zRoqnPjF6LZmQw1PuQ"
    locs=["Chickallasandra, Karnataka","Kyatasandra, Tumakuru","Bandra West, Mumbai","Bangalore Honnavar Road, Tumakuru"]
    lat_lng_pairs=[]
    for loc in locs:
        lat_lng=get_lat_ln(loc,mapquest_api_key)
        if len(lat_lng)>0:
            lat_lng_pairs.append(lat_lng)
    #print(lat_lng_pairs)
    dat=get_covid_data(lat_lng_pairs,coivd_api_key)
    for d in dat["data"]:
        print("Zone Name:{}".format(d["containmentZoneName"]))
        print("District:{}".format(d["district"]))
        print("Zone Type:{}\n".format(d["districtZoneType"]))
    print(type(dat))
