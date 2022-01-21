bool
Ipv4NixVectorRouting::BFS (uint32_t numberOfNodes, Ptr<Node> source, 
                           Ptr<Node> dest, std::vector< Ptr<Node> > & parentVector,
                           Ptr<NetDevice> oif) const
{
  NS_LOG_FUNCTION_NOARGS ();

  NS_LOG_LOGIC ("Going from Node " << source->GetId () << " to Node " << dest->GetId ());
  std::queue< Ptr<Node> > greyNodeList;  // discovered nodes with unexplored children

  // reset the parent vector
  parentVector.assign (numberOfNodes, 0); // initialize to 0

  // Add the source node to the queue, set its parent to itself 
  greyNodeList.push (source); //
  parentVector.at (source->GetId ()) = source;

  // BFS loop
  while (greyNodeList.size () != 0){
      Ptr<Node> currNode = greyNodeList.front (); //Trabajamos sobre el siguiente elemento de la cola
      Ptr<Ipv4> ipv4 = currNode->GetObject<Ipv4> (); //Obtenemos el objeto IPv4 del nodo actual
      
      //En caso de ser el nodo igual al destino, se termina el algoritmo
      if (currNode == dest) {
          NS_LOG_LOGIC ("Made it to Node " << currNode->GetId ());
          return true;
      }

      // if this is the first iteration of the loop and a 
      // specific output interface was given, make sure we go this way
      if (currNode == source && oif){

          //Se comprueba si el objeto IPv4 existe, y si la interfaz está activa
          if (ipv4){
              uint32_t interfaceIndex = (ipv4)->GetInterfaceForDevice (oif);
              if (!(ipv4->IsUp (interfaceIndex))){
                  NS_LOG_LOGIC ("Ipv4Interface is down");
                  return false;
              }
          }
          //Se comprueba si el enlace funciona
          if (!(oif->IsLinkUp ())){
              NS_LOG_LOGIC ("Link is down.");
              return false;
          }
          //Se comprueba si existe un canal
          Ptr<Channel> channel = oif->GetChannel ();
          if (channel == 0){ 
              return false;
          }

          //Obtenemos los dispositivos conectados al dispositivo indicado (oif)
          // this function takes in the local net dev, and channel, and
          // writes to the netDeviceContainer the adjacent net devs
          NetDeviceContainer netDeviceContainer;
          GetAdjacentNetDevices (oif, channel, netDeviceContainer);

          // Finally we can get the adjacent nodes and scan through them. We push them
          // to the greyNode queue, if they aren't already there.
          for (NetDeviceContainer::Iterator iter = netDeviceContainer.Begin (); iter != netDeviceContainer.End (); iter++){
              Ptr<Node> remoteNode = (*iter)->GetNode ();

              // check to see if this node has been pushed before by checking to see if it has a parent
              // if it doesn't (null or 0), then set its parent and push to the queue
              if (parentVector.at (remoteNode->GetId ()) == 0){
                  parentVector.at (remoteNode->GetId ()) = currNode;
                  greyNodeList.push (remoteNode);
              }
          }
      }
      else{
          // Iterate over the current node's adjacent vertices and push them into the queue
          for (uint32_t i = 0; i < (currNode->GetNDevices ()); i++){
              // Get a net device from the node as well as the channel, and figure
              // out the adjacent net device
              Ptr<NetDevice> localNetDevice = currNode->GetDevice (i);

              //Se comprueba si el objeto IPv4 existe, y si la interfaz está activa
              if (ipv4){
                  uint32_t interfaceIndex = (ipv4)->GetInterfaceForDevice (currNode->GetDevice (i));
                  if (!(ipv4->IsUp (interfaceIndex))){
                      NS_LOG_LOGIC ("Ipv4Interface is down");
                      continue;
                  }
              }
              //Se comprueba si el enlace funciona
              if (!(localNetDevice->IsLinkUp ())){
                  NS_LOG_LOGIC ("Link is down.");
                  continue;
              }
              //Se comprueba si existe un canal
              Ptr<Channel> channel = localNetDevice->GetChannel ();
              if (channel == 0){ 
                  continue;
              }

              //Obtenemos los dispositivos conectados al dispositivo indicado (oif)
              // this function takes in the local net dev, and channel, and
              // writes to the netDeviceContainer the adjacent net devs
              NetDeviceContainer netDeviceContainer;
              GetAdjacentNetDevices (localNetDevice, channel, netDeviceContainer);

              // Finally we can get the adjacent nodes and scan through them.  We push them
              // to the greyNode queue, if they aren't already there.
              for (NetDeviceContainer::Iterator iter = netDeviceContainer.Begin (); iter != netDeviceContainer.End (); iter++){
                  Ptr<Node> remoteNode = (*iter)->GetNode ();

                  // check to see if this node has been pushed before
                  // by checking to see if it has a parent
                  // if it doesn't (null or 0), then set its parent and 
                  // push to the queue
                  if (parentVector.at (remoteNode->GetId ()) == 0){
                      parentVector.at (remoteNode->GetId ()) = currNode;
                      greyNodeList.push (remoteNode);
                  }
              }
          }
      }
      // Pop off the head grey node.  We have all its children.
      // It is now black.
      greyNodeList.pop ();
  }
  // Didn't find the dest...
  return false;
}