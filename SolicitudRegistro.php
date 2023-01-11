<?php
    // Conseguir el domain de la request
    $domain = $_GET['domain'];
    //Dar un vistazo a la IP correspondiente al dominio en una BDD o archivo configuracion
    $ip = lookupIP($domain);

    // Armar la respuesta DNS
    $response = buildResponse($domain, 'A', $ip);
    //Devolver la respuesta al cliente
    sendResponse($response);
    

    // Funcion donde se buscaría el dominio en una BDD
    // Aqui un ejemplo hardcodeado, hay que hacerlo bien
    function lookupIP($domain)
    {
        return "192.168.1.100";
    }

    // Funcion donde se arma el paquete DNS que se enviara
    // Para el ejemplo responde un String
    function buildResponse($domain, $recordType, $recordData)
    {
        return "$domain $recordType $recordData";
    }

    // Funcion para mandar la respuesta al cliente
    // Para el ejemplo responde un String
    function sendResponse($response)
    {
        echo $response;
    }
?>
