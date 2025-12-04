npJson(jsonFile);
    if(inpJson.is_open()){
        inpJson >> jsonData;
        inpJson.close();
        cout <<"json file loaded\n";
    }else{
        cout <<"error while opening json file. Creating new file\n";
        jsonData = json::object();
    }