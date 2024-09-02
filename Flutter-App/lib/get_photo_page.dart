import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'dart:convert';

class GetPhotoPage extends StatefulWidget {
  @override
  _GetPhotoPageState createState() => _GetPhotoPageState();
}

class _GetPhotoPageState extends State<GetPhotoPage> {
  String _imageBase64 = '';

  @override
  void initState() {
    super.initState();
    _getImageFromFirebase();

  }

  final DatabaseReference _databaseReference = FirebaseDatabase.instance.ref('chunk');
  
  void _getImageFromFirebase() {
    
  //final DatabaseReference _databaseReference = FirebaseDatabase.instance.ref('chunk0');
  
    _databaseReference.onValue.listen((DatabaseEvent event) {
      final imageBase64 = event.snapshot.value as String?;
      if (imageBase64 != null) {
        setState(() {
          _imageBase64 = imageBase64;
        });
      }
    });
  
  
  
  // Container(
    //           height: 270,
    //           child: StreamBuilder<DatabaseEvent>(
    //             stream: _databaseReference
    //               .onValue,
    //               builder: (BuildContext context, AsyncSnapshot<DatabaseEvent> snapshot) {
    //               if (snapshot.hasData) {
    //                 if (snapshot.data!.snapshot.value != null) {

    //                   //final Map<dynamic, dynamic> dataMap = snapshot.data!.snapshot.value as Map<dynamic, dynamic>;
    //                   _imageBase64 = (snapshot.data).c_str();
    //                   //dataMap['imageBase64'];
    //                   //Map<dynamic, dynamic> dataMap = snapshot.data!.snapshot.value as Map<dynamic, dynamic>;
    //                 }}return Container();
    //                 }));
    //String imageRef = _databaseReference.child('images').child('captured_image').get();
    //_imageBase64 = imageRef.toString();
    // imageRef.once().then((DataSnapshot snapshot) {
    //   setState(() {
    //     _imageBase64 = snapshot.value;
    //   });
    // });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Image Viewer'),
      ),
      body: Center(
        child: Image.memory(
                base64Decode(_imageBase64),
                  //"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"),

                
                //int x = Base64Class::decode();
                fit: BoxFit.cover,
              )
           // : CircularProgressIndicator(),
      ),
    );
  }
}




// import 'dart:math';

// import 'package:flutter/material.dart';
// import 'package:firebase_database/firebase_database.dart';
// import 'dart:convert';
// import 'dart:typed_data';
// import 'dart:core';

// class GetPhotoPage extends StatefulWidget {
//   @override
//   _GetPhotoPageState createState() => _GetPhotoPageState();
// }

// class _GetPhotoPageState extends State<GetPhotoPage> {
//   List<String> _imageChunks = [];
//   Uint8List? _imageData;

//   @override
//   void initState() {
//     super.initState();
//     _getImageFromFirebase();
//   }

//   void _getImageFromFirebase() {
//     final DatabaseReference _databaseReference = FirebaseDatabase.instance.ref('images/captured_image');
    
//     _databaseReference.onValue.listen((DatabaseEvent event) {
//       final imageBase64 = event.snapshot.value as String?;
//       if (imageBase64 != null) {
//         setState(() {
//           _imageChunks = _splitBase64String(imageBase64);
//           _reconstructImage();
//         });
//       }
//     });
//   }

//   List<String> _splitBase64String(String base64String) {
//     // Example: Split into chunks of 1MB each (approximated)
//     const int chunkSize = 1024 * 1024; // 1MB
//     List<String> chunks = [];
//     for (int i = 0; i < base64String.length; i += chunkSize) {
//       int end = (i + chunkSize < base64String.length) ? i + chunkSize : base64String.length;
//       chunks.add(base64String.substring(i, end));
//     }
    
//     return chunks;
//   }

//   void _reconstructImage() {
//     if (_imageChunks.isEmpty) return;

//     // Combine chunks into a single base64 string
//     String combinedBase64 = _imageChunks.join('');
    
//     // Decode base64 string to bytes
//     _imageData = base64Decode(combinedBase64);
    
//     //console.log('Decoded image: $_imageData');

//   }

//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: Text('Image Viewer'),
//       ),
//       body: Center(
//         child: _imageData != null
//             ? Image.memory(
//                 _imageData!,
//                 fit: BoxFit.cover,
//               )
//             : CircularProgressIndicator(),
//       ),
//     );
//   }
// }
