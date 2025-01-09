const axios = require("axios");
const { response } = require("express");
const fs = require("fs/promises");
const path = require("path");

const token = "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";
const version = "2022-06-28";
const id = "fffc9007947f8124b1b5ed9bc4e7d1f7";
const header = {
    Authorization: `Bearer ${token}`,
    "Notion-Version": `${version}`,
};


const queryData = {
    "filter": {
        "and": [
            {
                "property": "WebPost",
                "checkbox": {
                    "equals": true
                }
            }
        ]
    }
}

const CACHE_DIR_DETAIL = path.join(__dirname, "detail");
const CACHE_DIR_SIMPLE = path.join(__dirname, "simple");

// 프로젝트 simple 리스트를 가져오는 함수수
async function getPjtList() {
    const url = `https://api.notion.com/v1/databases/${id}/query`;

    try {
        // axios.post를 await으로 처리
        const response = await axios.post(url, queryData, { headers: header });

        // 프로젝트 리스트 생성
        const pjtList = response.data.results.map((element) => {
            const stackList = element.properties["기술스택"]["multi_select"].map(
                (e) => e["name"]
            );

            return {
                id: element["id"],
                lastUpdate: element["last_edited_time"],
                title: element.properties["Name"]["title"]?.[0]?.["plain_text"] || "",
                summary: element.properties["프로젝트 개요"]["rich_text"]?.[0]?.["plain_text"] || "",
                team: element.properties["인원"]["number"],
                stacks: stackList,
                period: element.properties["기간"]["date"],
            };
        });
        // pjtList를 반환
        return pjtList;
    } catch (err) {
        console.error("오류 발생:", err);
        return []; // 오류 발생 시 빈 배열 반환
    }
}

// 프로젝트 ID를 기반으로 페이지의 블록을 가져오는 함수
async function getPjt(pjtID) {
    const url = `https://api.notion.com/v1/blocks/${pjtID}/children`;

    try {
        const response = await axios.get(url, { headers: header });

        const page = []; // 최상위 블록 저장

        // forEach 대신 for...of 사용
        for (const element of response.data.results) {
            // console.log("Processing block type:", element.type);

            let data = "";
            let child = []; // 하위 블록 초기화

            // 데이터와 하위 블록 처리
            switch (element.type) {
                case "paragraph":
                    if (element[element.type].rich_text.length === 0) break;
                    data = element[element.type].rich_text.map((text) => text.plain_text).join("");
                    break;

                case "image":
                    data = element[element.type].file.url;
                    break;

                case "heading_2":
                case "heading_3":
                    data = element[element.type].rich_text[0]?.text?.content || "";
                    break;

                case "numbered_list_item":
                case "bulleted_list_item":
                    data = element[element.type].rich_text.map((text) => text.plain_text).join("");
                    // 하위 블록 데이터 가져오기
                    const blockID = element.id;
                    child = await getBlock(blockID);
                    break;

                default:
                    data = "Unsupported block type";
            }

            // 블록 생성
            if (data) {
                page.push({ type: element.type, data, child });
            }
        }

        // console.log("페이지 데이터:", page);
        return page; // 결과 반환
    } catch (err) {
        console.error("오류 발생:", err);
        return [];
    }
}

// 블록 내의 데이터, 블록을 가져오기 위한 함수
async function getBlock(id) {
    const url = `https://api.notion.com/v1/blocks/${id}/children`;

    try {
        const response = await axios.get(url, { headers: header });

        // 하위 블록 처리
        const childBlocks = [];
        for (const block of response.data.results) {
            let data = "";
            let child = [];

            switch (block.type) {
                case "paragraph":
                    if (block[block.type].rich_text.length === 0) break;
                    data = block[block.type].rich_text.map((text) => text.plain_text).join("");
                    break;

                case "image":
                    data = block[block.type].file.url;
                    break;

                case "heading_2":
                case "heading_3":
                    data = block[block.type].rich_text[0]?.text?.content || "";
                    break;

                case "numbered_list_item":
                case "bulleted_list_item":
                    data = block[block.type].rich_text.map((text) => text.plain_text).join("");
                    // 하위 블록 재귀적으로 가져오기
                    const childBlockID = block.id;
                    child = await getBlock(childBlockID);
                    break;

                default:
                    data = "Unsupported block type";
            }
            // 블록 생성 및 추가
            if (data) {
                childBlocks.push({ type: block.type, data, child });
            }
        }

        return childBlocks; // 계층적으로 구성된 하위 블록 반환
    } catch (error) {
        console.error("하위 블록 가져오기 실패:", error);
        return [];
    }
}

// item의 최신 업데이트를 확인하는 함수수
async function checker(item) {
    const cacheFile = path.join(CACHE_DIR_SIMPLE, `${item["id"]}.json`);
    try {
        const cachedData = JSON.parse(await fs.readFile(cacheFile, "utf-8"));
        if (cachedData.lastUpdate == item["lastUpdate"]) {
            return cachedData;
        }
    }
    catch (error) {
        console.log(error);
    }
}

async function saveNewData(id){
    try{
        const newData = await getPjt(id);


    }catch(error){
        console.log(error);
    }
}






console.log("hi");

// getData();




module.exports = { getPjtList, getPjt };