/*exported updateMouseCount addPost menu main background changeStyle subpost*/
/*eslint-env browser*/

var count = 0, post_id = 0, remove_name; 

function addPost() {
    'use strict';
    
    var sel = document.getElementById("selectPOST"), post_index = sel.options[sel.selectedIndex].value, num_post = Number(document.getElementById("controlQ").value),  idname = "A" + post_index, i;
    for (i = 0; i < num_post; i++) {    
        post_id++;
        
        var divnode = document.createElement('div'), name = "A" + post_id, pnode = document.createElement('p'), dnode = document.createElement('p'), text_date = new Date(), dtextnode = document.createTextNode(text_date), butnode = document.createElement('button'),buttextnode = document.createTextNode("X"), ptext = document.getElementById("txt_post").value,
        ptextnode = document.createTextNode(ptext);
        
        divnode.id = (name);
        dnode.className = "date";
        dnode.appendChild(dtextnode);
        butnode.className = "button";
        remove_name = name;
        butnode.onclick = remove(remove_name);
        butnode.appendChild(buttextnode);
        divnode.appendChild(pnode);
        pnode.appendChild(dnode);
        dnode.appendChild(butnode);
        pnode.className =  changeStyle();
        pnode.appendChild(ptextnode);
        
        if (post_index > 0){
            divnode.className = "sub_post";
            var postnode = document.getElementById(idname);
            postnode.appendChild(divnode);
            document.getElementById("posts").appendChild(postnode);
        } else{                         
            document.getElementById("posts").appendChild(divnode);
        }
        

        var node = document.createElement("option");
        node.value = post_id;
        var subdtextnode = document.createTextNode(text_date);
        node.appendChild(subdtextnode);     document.getElementById("selectPOST").appendChild(node);
    }
}

function remove(name) {
    'use strict';
    
    var obj = document.getElementById(name);
    document.getElementById("posts").removeChild(obj);
}

function background(color) {
    "use strict";
    document.body.style.backgroundColor = color.value;
}

function updateMouseCount() {
    'use strict';
    document.getElementById('mcount').innerHTML = ++count;
}

function menu() {
    'use strict';
    document.getElementById("main").style.display = 'none'; 
    document.getElementById("menu").style.display = 'block';
}

function main() {
    'use strict';
    document.getElementById("main").style.display = 'block'; 
    document.getElementById("menu").style.display = 'none';
}

function changeStyle() {
    'use strict';
    
    var text_p;
    
    if (document.getElementById("controlblue").checked === true) {    
        if ((document.getElementById("controlB").checked === true) && (document.getElementById("controlI").checked === true)) {
            text_p = "colorblue styleI styleB";
        } else if (document.getElementById("controlB").checked === true) {
            text_p = "colorblue styleB";
        } else if (document.getElementById("controlI").checked === true) {
            text_p = "colorblue styleI";
        } else {
            text_p = "colorblue";
        }
    } else if (document.getElementById("controlred").checked === true) {     
        if ((document.getElementById("controlB").checked === true) && (document.getElementById("controlI").checked === true)) {
            text_p = "colorred styleI styleB";
        } else if (document.getElementById("controlB").checked === true) {
            text_p = "colorred styleB";
        } else if (document.getElementById("controlI").checked === true) {
            text_p = "colorred styleI";
        } else {
            text_p = "colorred";
        }
    }  else if ((document.getElementById("controlB").checked === true) && (document.getElementById("controlI").checked === true)) {
        text_p = "styleI styleB";
    } else if (document.getElementById("controlB").checked === true) {
        text_p = "styleB";
    } else if (document.getElementById("controlI").checked === true) {
        text_p = "styleI";
    } else {
        text_p = " ";
    }
    
    return text_p;
}

