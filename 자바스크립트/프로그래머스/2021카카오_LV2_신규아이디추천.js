function solution(new_id) {
    var answer = '';
    
    new_id= new_id.toLowerCase();
    new_id = new_id.match(/[a-z0-9-_.]/g).join('')
    new_id = new_id.replace(/\.+/g,".")
    if (new_id[0]=== ".")
        new_id =new_id.slice(1,new_id.length);
    if (new_id[new_id.length-1]=== ".")
          new_id = new_id.slice(0,new_id.length-1);
    new_id = new_id === "" ? "a" : new_id;
    if(new_id.length > 15) {
        new_id = new_id.slice(0,15);
        if(new_id[14] === ".")
            new_id=new_id.slice(0,14);
    }
    while(new_id.length < 3)
    {
        new_id+= new_id[new_id.length-1];
    }
    return new_id;
}