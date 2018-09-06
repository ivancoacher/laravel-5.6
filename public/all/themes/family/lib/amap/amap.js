/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

   

//    jQuery.each(json_directory, function(i, item) {
//          console.log(item);
//          var marker= new AMap.Marker({ //添加自定义点标记
//            map: map,
//            position: [item.lat, item.long], //基点位置
//            offset: new AMap.Pixel(-17, -42), //相对于基点的偏移位置
//            draggable: false,  //是否可拖动
//            content: '<div class="marker-route marker-marker-bus-from">  <img src="'+item.img+'" class="map-img-item" /></div>'   //自定义点标记覆盖物内容
//        });
//        marker.on('click',function(e){
//                    marker.markOnAMAP({
//                        name:'首开广场',
//                        position:marker.getPosition()
//                    })
//                });   
//        });
// 
//  var center_lat=0;
//  var center_long=0
//    jQuery.each(json_directory, function(i, item) {
//       if(i==0){
//            center_lat= item.lat ;
//            center_long = item.long;
//       }
//    });
//      
//   var map = new AMap.Map("map-content", {
//        resizeEnable: true,
//      //  center: [31.11, 121.57],//地图中心点
//        zoom: 1 //地图显示的缩放级别
//        });
//    jQuery.each(json_directory, function(i, item) {
//          console.log(item);
//  
//       var marker= new AMap.Marker({ //添加自定义点标记
//            map: map,
//            position: [item.lat, item.long], //基点位置
//            offset: new AMap.Pixel(-17, -42), //相对于基点的偏移位置
//            draggable: false,  //是否可拖动
//            content: '<div class="marker-route marker-marker-bus-from">  <img src="'+item.img+'" class="map-img-item" /></div>'   //自定义点标记覆盖物内容
//        });
//        marker.on('click',function(e){
//                    marker.markOnAMAP({
//                        name:'首开广场',
//                        position:marker.getPosition()
//                    })
//                });  
//                
//                
//
//    
//        });
//        
//                
//        map.setLang("en");
//        map.setFitView();
// 

var map = new AMap.Map('map-content',{
        resizeEnable: true,
        zoom:11,
        scrollWheel:false,
        center: [121.47, 31.22]
    });
    var markers = [];

//    var marker = new AMap.Marker({
//        position: [116.48, 39.98],
//        map: map
//    });
//    markers.push(marker);
var i=0;
  var count = Object.keys(json_directory).length;
    jQuery.each(json_directory, function(i, item) {
        console.log(item); 
        i++;
        var map_image=item.img ; 
        var image = new Image(); 
        image.src = map_image;
        if (image.width == 0||!image.complete || typeof image.naturalWidth == "undefined" || image.naturalWidth == 0) {
          map_image =default_image ;
        }

       var marker= new AMap.Marker({ //添加自定义点标记
            map: map,
            position: [item.long,item.lat], //基点位置
            offset: new AMap.Pixel(-17, -42), //相对于基点的偏移位置
            draggable: false,  //是否可拖动
            content: '<div class="marker-route marker-marker-bus-from">  <img src="'+map_image+'" class="map-img-item" /></div>'   //自定义点标记覆盖物内容
        });
        if(item.url == ""){  
        marker.on('click',function(e){                                 
                   window.location = item.url ;                
                });  
        }
     
        if(count==i&&count==1){
           map.setZoomAndCenter(17, [item.long,item.lat]);        
        }else{
           map.setFitView();
        }        
        markers.push(marker);
        });
        
//    var marker = new AMap.Marker({
//        position: [126.48, 43.98],
//        title: '11111',
//        map: map
//    });
//    markers.push(marker);
        map.setLang("en");
      map.plugin(["AMap.ToolBar"], function() {
            map.addControl(new AMap.ToolBar());
    });

