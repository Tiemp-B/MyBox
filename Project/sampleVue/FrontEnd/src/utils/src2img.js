export async function loadImage(src){
    const url2file = async(url)=> await fetch(url).then((res)=> res.blob())

    const blob2Base64 = (blob)=>{
        const reader = new FileReader()
        reader.readAsDataURL(blob)
        return new Promise((rs, rj)=>{
            reader.onloadend = ()=>{
                rs(reader.result)
            }
            reader.onerror = rj
        })
    }
    return new Promise((resolve)=>{
        const img = new Image()
        img.src = src + "?newTime="+ new Date().getTime()
        img.crossOrigin = "Anonymous"
        img.onload = async()=>{
            const blob = await url2file(src + "?newTime="+ new Date().getTime())
            const base64 = await blob2Base64(blob)
            resolve({
                height: img.height, width: img.width, src: base64})
        }
    })
}


