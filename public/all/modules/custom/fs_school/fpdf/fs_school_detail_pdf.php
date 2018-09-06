<?php

use Endroid\QrCode\QrCode;

$file_path = '';

class PDF extends FPDF {

// Page header
    function Header() {
        //Logo Image
        $this->Image('http://family.cityweekend.com.cn/sites/default/files/logo_0.png',10,5,30);
        $this->Ln(20);
    }

    function Footer() {
        $this->Ln();
        $this->SetTextColor(000);
        $this->SetFont('Times', '', 8);
        $this->Cell(0, 10, 'http://family.cityweekend.com.cn/');
    }

    function FancyTable($item) {
        $academic_program = '';
        $curriculam = '';
        $taught_languages = '';
        $tuition_fee ="";
        $logo =  $item['logo'];
        $image = $item['image'];
        $address = $item['address'];
        $title =  $item['title'];
        $description = $item['description'];
        $foundation_date = $item['foundation_date'];
        $school_type = $item['school_type']->name;
        $minimum_tuition = $item['minimum_tuition'];
        $maximum_tuition = $item['maximum_tuition'];
        $email = $item['email'];
        $website = $item['website'];
        $inquiry = $item['inquiry'];
        $neighborhood = $item['neighborhood']->name;
        $phone = $item['phone'];
        $file_path = drupal_get_path('module', 'fs_school');
        //Array to String for pdf
        foreach ($item['curriculum'] as $val) {
            if ($curriculam != '') {
                $curriculam = $curriculam . ',' . $val->name;
            } else {
                $curriculam = $curriculam . ' ' . $val->name;
            }
        }
        foreach ($item['academic_program'] as $val) {
            if ($academic_program != '') {
                $academic_program = $academic_program . ',' . $val->name;
            } else {
                $academic_program = $academic_program . ' ' . $val->name;
            }
        }
        foreach ($item['taught_languages'] as $val) {
            if ($taught_languages != '') {
                $taught_languages = $taught_languages . ',' . $val->name;
            } else {
                $taught_languages = $taught_languages . ' ' . $val->name;
            }
        }
        
        //Frame/border colour
        $this->SetDrawColor(205, 201, 201);
        if($inquiry){
        generate_qrcode((string)  addhttp($inquiry),'qr_take_tour.png','Book a tour');    
        $this->Image($file_path.'/qr_take_tour.png',140,5,20);
        }
        if($website){
         generate_qrcode((string)  addhttp($website),'qr_visit.png','Visit website');    
        $this->Image($file_path.'/qr_visit.png',170,5,20);
        }
        //Title
        $this->SetFont('Times', '', 18);
        $this->SetTextColor(70, 130, 180);
 
        //generate_qrcode("Hello CW",'qr_take_tour.png');
        
        //Row School Logo and title
        if(getimagesize($logo)>0){
        $this->Cell(35, 5, $this->Image($logo, 10, 25, 30), 0, 0, 'L');
        }else{
            $this->Cell(35, 5, $this->Image("http://family.cityweekend.com.cn/sites/all/themes/family/images/default.jpeg", 10, 25, 30), 0, 0, 'L');
        }
        $this->Cell(0, 7, $title);
        $this->Ln(8);
        $this->SetFont('Times', '', 10);
        $this->SetTextColor(105, 105, 105);
        $this->Cell(35, 5);
        $this->MultiCell(0, 5, $address);
        $this->Ln(4);
        //End of Row
        // School Main Image 
        if(getimagesize($image)>0){
        $this->Cell(0,70,$this->Image($image, 70, 60,70),0,30);
        }else{}
        if(isset($item['mission'])){
        //School Misson
        $this->SetFont('Times', 'I', 10);
        $this->SetTextColor(70, 130, 180);
        $this->Cell(30, 5, ' ', 0, 0, 'L');
        $this->MultiCell(120, 5, ' " ' . $item['mission'] . ' " ');
        $this->Ln(8);
        }
        
        // About title
        $this->SetFont('Times', '', 14);
        $this->SetTextColor(70, 130, 180);
        $this->Cell(0, 10, 'School Information');
        $this->Ln(12);

       
        // About School
        $this->SetFont('Times', '', 10);
        $this->SetTextColor(000);
        
        if(isset($description)){
        $this->MultiCell(0, 5, $item['description']);
        $this->Ln(5);
        }

        if(isset($foundation_date)){
        //Row
        $this->Cell(60, 5, 'Date Founded', 0, 0, 'L');
        $this->MultiCell(130, 5, $foundation_date);
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        
        if(isset($neighborhood)){
        //Row
        $this->Cell(60, 5, 'Neighborhood', 0, 0, 'L');
        $this->MultiCell(130, 5,$neighborhood);
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        
        
        //Row
        $this->Cell(60, 5, 'Grade Levels', 0, 0, 'L');
        $this->MultiCell(130, 5, count($item['campuses']));
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        if($school_type != ""){
        //Row
        $this->Cell(60, 5, 'School Type', 0, 0, 'L');
        $this->MultiCell(130, 5, $item['school_type']->name, 0, 'L');
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        if(isset($curriculam)){
        //Row
        $this->Cell(60, 5, 'Curriculum', 0, 0, 'L');
        $this->MultiCell(130, 5, trim($curriculam), 0, 'L');
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        if(isset($taught_languages)){
        //Row
        $this->Cell(60, 5, 'Languages Taught', 0, 0, 'L');
        $this->MultiCell(130, 5, trim($taught_languages));
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        if(isset($academic_program)){
        //Row
        $this->Cell(60, 5, 'School Strengths', 0, 0, 'L');
        $this->MultiCell(130, 5, trim($academic_program));
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        
        if($minimum_tuition !="" && $maximum_tuition != ""){
           $tuition_fee = $item['minimum_tuition'] . ' - ' . $item['maximum_tuition'];
        }else if($minimum_tuition !=""){
            $tuition_fee = $minimum_tuition;
        }else if($maximum_tuition != ""){
            $tuition_fee = $maximum_tuition;
        }
        if(isset($tuition_fee)){
        //Row
        $this->Cell(60, 5, 'Annual Tuition', 0, 0, 'L');
        $this->MultiCell(130, 5, 
                $tuition_fee . ' rmb');
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        if(isset($email)){
        //Row
        $this->Cell(60, 5, 'Email', 0, 0, 'L');
        $this->MultiCell(130, 5, $email);
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        
        if(isset($phone)){
        //Row
        $this->Cell(60, 5, 'Telephone', 0, 0, 'L');
        $this->MultiCell(130, 5, $phone);
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        //End of Row
        }
        
        if(isset($website)){
        //Row
        $this->Cell(60, 5, 'Website', 0, 0, 'L');
        $this->MultiCell(130, 5, $website);
        //Border
        $this->Cell(0, 2, '', 'B', 0, 'L');
        $this->Ln(4);
        }
        //End of Row
        
        if(isset($item['campuses'][0]->field_address_in_english['und'][0]['value'])){
        //Campuses in Shanghai
        $this->SetFont('Times', '', 12);
        $this->SetTextColor(70, 130, 180);
        $this->Cell(10, 10, 'Campuses in Shanghai');
        $this->Ln(12);
        $this->SetTextColor(000);
        $this->SetFont('Times', '', 10);

        foreach ($item['campuses'] as $campus) {
            //Row
            $this->SetTextColor(70, 130, 180);
            $this->Cell(0, 10, $campus->field_school_campuse_title['und'][0]['value'], 0, 0, 'L');
            $this->Ln(8);
            //End of Row
            $this->SetTextColor(000);
            //Row
            $this->Cell(60, 5, 'Address', 0, 0, 'L');
            $this->MultiCell(130, 5, $campus->field_address_in_english['und'][0]['value']);
            //Border
            $this->Cell(0, 2, '', 'B', 0, 'L');
            $this->Ln(4);
            //End of Row
            //Row
            $this->Cell(60, 5, 'Telephone', 0, 0, 'L');
            $this->MultiCell(130, 5, $campus->field_telephone['und'][0]['value']);
            //Border
            $this->Cell(0, 2, '', 'B', 0, 'L');
            $this->Ln(4);
            //End of Row
            //Row
            $this->Cell(60, 5, 'Contact Email', 0, 0, 'L');
            $this->MultiCell(130, 5, $campus->field_email['und'][0]['email']);
            //Border
            $this->Cell(0, 2, '', 'B', 0, 'L');
            $this->Ln(4);
            //End of Row
        }
        }
    }

}

function generate_pdf($item) {
    
    $pdf = new PDF('P', 'mm', 'A4');
// Data loading
    $pdf->AddPage();
    $pdf->FancyTable($item);
    $pdf->Output('D', $item['title'] . '_details.pdf');
}

function generate_qrcode($text,$filename,$label) {
    $file_path = drupal_get_path('module', 'fs_school');
    $val = '';
    $qrCode = new QrCode();
    $qrCode->setText($text)
            ->setSize(100)
            ->setPadding(5)
            ->setErrorCorrection('high')
            ->setForegroundColor(array('r' => 0, 'g' => 0, 'b' => 0, 'a' => 0))
            ->setBackgroundColor(array('r' => 255, 'g' => 255, 'b' => 255, 'a' => 0))
            // Path to your logo with transparency
            // Set the size of your logo, default is 48
            ->setLogoSize(20)
            ->setLabel($label)
            ->setLabelFontSize(12)
            ->setImageType(QrCode::IMAGE_TYPE_PNG);
    $qrCode->save($file_path . '/'.$filename);
}


