/*exported updateMouseCount addPost menu main background changeStyle subpost*/
/*eslint-env browser*/

var count = 0, post_id = 0;

function removePost(index){
    "use strict";
    $(index).parent().remove();  
}

function background(color) {
    "use strict";
    $("body").css("background-color", color.value);  
}

function updateMouseCount() {
    'use strict';
    $("#mcount").text(++count);
}

function menu() {
    'use strict';
     $("#main").hide(); 
     $("#menu").show(); 
}

function main() {
    'use strict';
     $("#main").show(); 
     $("#menu").hide();
}

function changeStyle() {
    'use strict';
    
     var text_p;
    
    if ($("#controlblue").prop("checked")) {    
        if (($("#controlB").prop("checked")) && ($("#controlI").prop("checked"))) {
            text_p = "colorblue styleI styleB";
        } else if ($("#controlB").prop("checked")) {
            text_p = "colorblue styleB";
        } else if ($("#controlI").prop("checked")) {
            text_p = "colorblue styleI";
        } else {
            text_p = "colorblue";
        }
    } else if ($("#controlred").prop("checked")) {     
        if (($("#controlB").prop("checked")) && ($("#controlI").prop("checked"))) {
            text_p = "colorred styleI styleB";
        } else if ($("#controlB").prop("checked")) {
            text_p = "colorred styleB";
        } else if ($("#controlI").prop("checked")) {
            text_p = "colorred styleI";
        } else {
            text_p = "colorred";
        }
    }  else if (($("#controlB").prop("checked")) && ($("#controlI").prop("checked"))) {
        text_p = "styleI styleB";
    } else if ($("#controlB").prop("checked")) {
        text_p = "styleB";
    } else if ($("#controlI").prop("checked")) {
        text_p = "styleI";
    } else {
        text_p = " ";
    }
    return text_p;
}


function addPost() {
    'use strict';
    var post_index = $("#selectPOST").prop('selectedIndex');
    var num_post = $("#controlQ").val();

    var i;
    for (i = 0; i < num_post; i++) {    
        post_id++;
        
        var div_id = "A" + post_id;
        var text_date = new Date(); 
        var ptext = $("#txt_post").val();
        
        var divnode = $("<div></div>");
        var dnode = $("<span></span>").text(text_date).addClass("date");
        var butnode = $("<button></button>").text("X").addClass("button");
        butnode.attr('onClick', 'removePost(this);');
        var pnode = $("<p></p>").text(ptext).addClass(changeStyle());
        var postnode = $("<div></div>").attr("id", div_id);
        
        divnode.append(dnode).append(butnode).append(pnode).append(postnode);
        $("#posts").append(divnode);
        
        var node = $("<option></option>").attr("id", post_id).text(text_date);
        $("#selectPOST").append(node);
        
        if (post_index > 0){
            divnode.addClass("subpost");
            var iderr = "A" + $("#selectPOST").children(":selected").attr("id");
            $('#' + iderr).append(divnode);
        } else{                         
            $("#posts").append(divnode);
        }
    }
}
